import pygame
import sys
from collections import deque, defaultdict
import math
import time

# --- Colors / Constants ---
PRIMARY_DARK = (41, 53, 65)    
SECONDARY_ACCENT = (52, 152, 219) 
PROCESSING_COLOR = (243, 156, 18)
VISITED_COLOR = (46, 204, 113)  
BACKGROUND_COLOR = (249, 249, 249) 
GRAPH_BG = (255, 255, 255)     
TEXT_LIGHT = (255, 255, 255)    
TEXT_DARK = PRIMARY_DARK        
BUTTON_NORMAL = (200, 200, 200) 
BUTTON_HOVER = (170, 170, 170) 
BUTTON_ACTIVE = SECONDARY_ACCENT 

NODE_RADIUS = 20
FPS = 60
BORDER_RADIUS = 8 

class Button:
    def __init__(self, x, y, w, h, text, is_primary=False, is_toggle=False):
        self.rect = pygame.Rect(x, y, w, h)
        self.text = text
        self.is_primary = is_primary
        self.is_toggle = is_toggle
        self.is_active = False
        self.hovered = False

    def draw(self, surf, font):
        # Determine base color
        if self.is_toggle and self.is_active:
            color = BUTTON_ACTIVE
        elif self.is_primary:
            color = SECONDARY_ACCENT
        else:
            color = BUTTON_NORMAL

        # Apply hover effect
        if self.hovered and not self.is_active:
             # Darker hover for normal, lighter/brighter for primary
            if self.is_primary:
                color = (70, 170, 235) # Slightly lighter blue
            else:
                color = BUTTON_HOVER

        # Draw main rectangle
        pygame.draw.rect(surf, color, self.rect, border_radius=BORDER_RADIUS)
        
        # Draw border only for non-primary/non-active toggle
        if not self.is_primary and not (self.is_toggle and self.is_active):
            pygame.draw.rect(surf, PRIMARY_DARK, self.rect, 1, border_radius=BORDER_RADIUS)

        # Determine text color
        if self.is_primary or (self.is_toggle and self.is_active):
            text_color = TEXT_LIGHT
        else:
            text_color = TEXT_DARK
            
        txt = font.render(self.text, True, text_color)
        surf.blit(txt, txt.get_rect(center=self.rect.center))

    def update_hover(self, pos):
        self.hovered = self.rect.collidepoint(pos)

    def clicked(self, pos):
        return self.rect.collidepoint(pos)

class GraphVisualizer:
    def __init__(self, nodes, edges):
        self.nodes = nodes      # dict: id -> (x,y)
        self.edges = edges      # list of (u,v)
        self.node_colors = {n: SECONDARY_ACCENT for n in nodes}
        self.is_running = False
        self.is_paused = False
        self.steps = []
        self.current_index = 0
        self.interval = 700     # ms between steps
        self.last_time = 0

    def draw(self, surf, font):
        # graph background
        # Note: 560x420 is preserved for structure.
        pygame.draw.rect(surf, GRAPH_BG, (10,10,560,420), border_radius=BORDER_RADIUS)
        pygame.draw.rect(surf, PRIMARY_DARK, (10,10,560,420), 2, border_radius=BORDER_RADIUS)

        # edges
        for u,v in self.edges:
            self.draw_edge(surf, u, v)
        # nodes
        for nid,(x,y) in self.nodes.items():
            self.draw_node(surf, font, nid, x, y)

    def draw_node(self, surf, font, nid, x, y):
        c = self.node_colors.get(nid, SECONDARY_ACCENT)
        # Main circle fill
        pygame.draw.circle(surf, c, (x,y), NODE_RADIUS)
        # Outline
        pygame.draw.circle(surf, PRIMARY_DARK, (x,y), NODE_RADIUS, 2)
        
        # Text
        # Use TEXT_LIGHT for all colored nodes for better contrast
        text_color = TEXT_LIGHT
        txt = font.render(str(nid), True, text_color)
        surf.blit(txt, txt.get_rect(center=(x,y)))

    def draw_edge(self, surf, u, v):
        x1,y1 = self.nodes[u]
        x2,y2 = self.nodes[v]
        dx,dy = x2-x1, y2-y1
        dist = math.hypot(dx,dy) or 1
        
        # Adjust line start/end to node circumference
        x1_adj = x1 + (dx/dist)*NODE_RADIUS
        y1_adj = y1 + (dy/dist)*NODE_RADIUS
        x2_adj = x2 - (dx/dist)*NODE_RADIUS
        y2_adj = y2 - (dy/dist)*NODE_RADIUS
        
        # Draw line
        pygame.draw.line(surf, PRIMARY_DARK, (x1_adj,y1_adj),(x2_adj,y2_adj), 2)
        
        # Draw arrowhead
        angle = math.atan2(dy,dx)
        arrow = 8
        px = x2_adj - math.cos(angle)*arrow * 0.5 # Arrow base back a bit
        py = y2_adj - math.sin(angle)*arrow * 0.5
        p1 = (px + math.cos(angle+2.4)*arrow, py + math.sin(angle+2.4)*arrow)
        p2 = (x2_adj, y2_adj)
        p3 = (px + math.cos(angle-2.4)*arrow, py + math.sin(angle-2.4)*arrow)
        pygame.draw.polygon(surf, PRIMARY_DARK, [p1,p2,p3])

    def set_steps(self, steps, interval_ms=700):
        self.steps = steps
        self.current_index = 0
        self.interval = interval_ms
        self.last_time = pygame.time.get_ticks()
        self.is_running = True
        self.is_paused = False
        # reset visual colors for any nodes not already visited
        for n in self.node_colors:
            self.node_colors[n] = SECONDARY_ACCENT

    def update(self):
        if not self.is_running or self.is_paused:
            self.last_time = pygame.time.get_ticks()
            return

        now = pygame.time.get_ticks()
        if now - self.last_time >= self.interval:
            if self.current_index < len(self.steps):
                node, state = self.steps[self.current_index]
                # Apply state
                self.node_colors[node] = state
                self.current_index += 1
            else:
                self.is_running = False
            self.last_time = now

    def reset(self):
        self.is_running = False
        self.is_paused = False
        self.steps = []
        self.current_index = 0
        for n in self.node_colors:
            self.node_colors[n] = SECONDARY_ACCENT

# Topological algorithms (no changes needed here, logic is sound)
def topological_sort_dfs(graph, nodes):
    visited = set()
    steps = []
    def dfs(u):
        visited.add(u)
        steps.append((u, PROCESSING_COLOR))
        for v in graph.get(u, []):
            if v not in visited:
                dfs(v)
        steps.append((u, VISITED_COLOR))
    for u in nodes:
        if u not in visited:
            dfs(u)
    return steps

def topological_sort_kahn(graph, nodes, edges):
    in_deg = {n:0 for n in nodes}
    adj = defaultdict(list)
    for u,v in edges:
        adj[u].append(v)
        in_deg[v] += 1
    q = deque([n for n in nodes if in_deg[n]==0])
    steps = []
    result = []
    while q:
        u = q.popleft()
        steps.append((u, PROCESSING_COLOR))
        result.append(u)
        for v in adj[u]:
            in_deg[v] -= 1
            if in_deg[v]==0:
                q.append(v)
        steps.append((u, VISITED_COLOR))
    if len(result) != len(nodes):
        return None # Cycle detected
    return steps

class TopologicalSortApp:
    def __init__(self):
        pygame.init()
        # laptop-friendly window
        self.width, self.height = 900, 600
        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Topological Sort Visualizer")
        self.clock = pygame.time.Clock()

        # fonts (using a more prominent size for title)
        self.font_title = pygame.font.SysFont('Arial', 32, bold=True)
        self.font_medium = pygame.font.SysFont('Arial', 20)
        self.font_small = pygame.font.SysFont('Arial', 16)

        # sample graph (coordinates are fine, within the 560x420 box)
        self.nodes = {1:(100,120), 2:(220,60), 3:(220,180), 4:(360,120), 5:(480,60), 6:(480,180)}
        self.edges = [(1,2),(1,3),(2,4),(3,4),(4,5),(4,6)]
        self.graph = {1:[2,3],2:[4],3:[4],4:[5,6],5:[],6:[]}

        self.visualizer = GraphVisualizer(self.nodes, self.edges)
        self.current_algo = "DFS"
        self.topo_result = []

        # buttons positions (Moved and grouped logically)
        # Algorithm Toggles
        bx1, by = 30, 450
        self.buttons = {
            "dfs": Button(bx1, by, 80, 40, "DFS", is_toggle=True),
            "kahn": Button(bx1 + 90, by, 90, 40, "Kahn's", is_toggle=True),
        }
        
        # Control Buttons
        by_c = by + 50
        self.buttons.update({
            "run": Button(bx1, by_c, 80, 40, "Run", is_primary=True),
            "pause": Button(bx1 + 90, by_c, 80, 40, "Pause"),
            "resume": Button(bx1 + 180, by_c, 90, 40, "Resume"),
            "reset": Button(bx1 + 280, by_c, 90, 40, "Reset", is_primary=True),
        })
        
        self.buttons["dfs"].is_active = True

    def run_algorithm(self):
        if self.visualizer.is_running and not self.visualizer.is_paused:
            return
        self.visualizer.reset()
        self.topo_result = []
        
        if self.current_algo == "DFS":
            steps = topological_sort_dfs(self.graph, self.nodes.keys())
        else:
            steps = topological_sort_kahn(self.graph, self.nodes.keys(), self.edges)
            if steps is None:
                # This will be handled visually in the info panel
                steps = []
        
        self.visualizer.set_steps(steps, interval_ms=700)

    def handle_events(self):
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                pygame.quit(); sys.exit()
            elif ev.type == pygame.MOUSEMOTION:
                for b in self.buttons.values():
                    b.update_hover(ev.pos)
            elif ev.type == pygame.MOUSEBUTTONDOWN and ev.button==1:
                pos = ev.pos
                # Toggle algorithm buttons
                if self.buttons["dfs"].clicked(pos):
                    self.current_algo = "DFS"
                    self.buttons["dfs"].is_active = True
                    self.buttons["kahn"].is_active = False
                    self.visualizer.reset()
                    self.topo_result = []
                elif self.buttons["kahn"].clicked(pos):
                    self.current_algo = "Kahn's"
                    self.buttons["kahn"].is_active = True
                    self.buttons["dfs"].is_active = False
                    self.visualizer.reset()
                    self.topo_result = []
                # Control buttons
                elif self.buttons["run"].clicked(pos):
                    self.run_algorithm()
                elif self.buttons["pause"].clicked(pos):
                    self.visualizer.is_paused = True
                elif self.buttons["resume"].clicked(pos):
                    if self.visualizer.steps:
                        self.visualizer.is_paused = False
                        self.visualizer.last_time = pygame.time.get_ticks()
                elif self.buttons["reset"].clicked(pos):
                    self.visualizer.reset()
                    self.topo_result = []

    def update_result_list(self):
        # Update topo_result: collects 'VISITED' nodes
        res = []
        for i in range(self.visualizer.current_index):
            node, state = self.visualizer.steps[i]
            if state == VISITED_COLOR and node not in res:
                res.append(node)
        self.topo_result = res

    def draw_info_panel(self):
        # right panel area (rx=590, rw=300)
        rx = 590; ry = 10; rw = self.width - rx - 10; rh = self.height - 20
        pygame.draw.rect(self.screen, GRAPH_BG, (rx,ry,rw,rh), border_radius=BORDER_RADIUS)
        pygame.draw.rect(self.screen, PRIMARY_DARK, (rx,ry,rw,rh), 2, border_radius=BORDER_RADIUS)

        # --- Section 1: Title and Status ---
        ty = ry + 15
        t = self.font_title.render("Topological Sort", True, PRIMARY_DARK)
        self.screen.blit(t, (rx+15, ty))
        
        pygame.draw.line(self.screen, BUTTON_NORMAL, (rx+15, ty+45), (rx+rw-15, ty+45), 1)
        
        # Status
        status_text = "Ready"
        status_color = SECONDARY_ACCENT
        if self.visualizer.is_running and not self.visualizer.is_paused:
            status_text = "Running..."
            status_color = PROCESSING_COLOR
        elif self.visualizer.is_paused:
            status_text = "Paused"
            status_color = PROCESSING_COLOR # still use active color
        
        status_s = self.font_medium.render(f"Status: {status_text}", True, status_color)
        self.screen.blit(status_s, (rx+15, ty+58))
        
        algo = self.font_medium.render(f"Algorithm: {self.current_algo}", True, PRIMARY_DARK)
        self.screen.blit(algo, (rx+15, ty+88))

        # Current step (more concise)
        if self.visualizer.steps:
            progress_percent = int((self.visualizer.current_index / len(self.visualizer.steps)) * 100)
            step_txt = self.font_medium.render(f"Progress: {self.visualizer.current_index}/{len(self.visualizer.steps)} steps ({progress_percent}%)", True, PRIMARY_DARK)
            self.screen.blit(step_txt, (rx+15, ty+118))
        else:
            step_txt = self.font_medium.render("No simulation loaded", True, PRIMARY_DARK)
            self.screen.blit(step_txt, (rx+15, ty+118))
        
        
        # --- Section 2: Result List ---
        ry_res = ty + 160
        result_txt = self.font_medium.render("Topological Order:", True, PRIMARY_DARK)
        self.screen.blit(result_txt, (rx+15, ry_res))
        
        # Display Result
        self.update_result_list()
        res_s = " \u2192 ".join(map(str,self.topo_result)) if self.topo_result else "..."
        if self.current_algo == "Kahn's" and self.visualizer.is_running == False and len(self.topo_result) < len(self.nodes):
            res_s = "Cycle Detected! \u274C"
            res_render = self.font_medium.render(res_s, True, PROCESSING_COLOR) # Use the warning color
        else:
            res_render = self.font_medium.render(res_s, True, VISITED_COLOR)
        
        # Result Box with border/background
        res_rect = pygame.Rect(rx+15, ry_res+30, rw-30, 36)
        pygame.draw.rect(self.screen, BACKGROUND_COLOR, res_rect, border_radius=4)
        pygame.draw.rect(self.screen, PRIMARY_DARK, res_rect, 1, border_radius=4)
        self.screen.blit(res_render, (rx+22, ry_res+35))

        
        # --- Section 3: Algorithm Description ---
        ry_desc = ry_res + 90
        self.screen.blit(self.font_medium.render("Description:", True, PRIMARY_DARK), (rx+15, ry_desc))
        
        desc = ("DFS: post-order traversal; nodes added to order after all descendants are visited. O(V+E)"
                if self.current_algo == "DFS"
                else "Kahn: Iteratively selects nodes with zero in-degree until all nodes are placed. Detects cycles. O(V+E)")
        
        # wrap description
        words = desc.split(' ')
        line = ""
        y = ry_desc + 30
        for w in words:
            test = (line + " " + w).strip()
            if self.font_small.size(test)[0] > rw-30:
                self.screen.blit(self.font_small.render(line, True, PRIMARY_DARK), (rx+15, y))
                y += 20 # Increased line height for legibility
                line = w
            else:
                line = test
        if line:
            self.screen.blit(self.font_small.render(line, True, PRIMARY_DARK), (rx+15, y))
            y += 22
        

        # --- Section 4: Legend ---
        ry_legend = y + 20
        self.screen.blit(self.font_medium.render("Legend:", True, PRIMARY_DARK), (rx+15, ry_legend))
        
        # Draw legend items in two columns for better use of space
        legend_items = [
            ("Unvisited", SECONDARY_ACCENT),
            ("Processing", PROCESSING_COLOR),
            ("Visited", VISITED_COLOR)
        ]
        
        ly = ry_legend + 30
        col_w = rw // 2
        
        for i, (text, color) in enumerate(legend_items):
            lx = rx + 15 
            pygame.draw.circle(self.screen, color, (lx+10, ly+8), 8)
            self.screen.blit(self.font_small.render(text, True, PRIMARY_DARK), (lx+30, ly))
            ly += 25


    def draw(self):
        self.screen.fill(BACKGROUND_COLOR)
        # left graph area (handled by visualizer)
        self.visualizer.draw(self.screen, self.font_medium)

        # draw info panel (right)
        self.draw_info_panel()
        
        # draw buttons
        for b in self.buttons.values():
            b.draw(self.screen, self.font_medium)

        pygame.display.flip()

    def run(self):
        while True:
            self.handle_events()
            self.visualizer.update()
            self.draw()
            self.clock.tick(FPS)

if __name__ == "__main__":
    app = TopologicalSortApp()
    app.run()