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
# Button Color Enhancements:
BUTTON_NORMAL = (236, 240, 241) # Lighter neutral base (cloud)
BUTTON_HOVER = (210, 215, 218) # Slightly darker on hover
BUTTON_ACTIVE = SECONDARY_ACCENT # Primary action color (blue)
BUTTON_BORDER = (189, 195, 199) # Darker border for depth
BUTTON_PRIMARY_HOVER = (84, 172, 239) # Lighter blue hover

# UI FIX: New color for active toggle states (using VISITED_COLOR for contrast)
TOGGLE_ACTIVE = VISITED_COLOR 

EDGE_TEMP = (255, 99, 71) 

NODE_RADIUS = 20
FPS = 60
BORDER_RADIUS = 8 

# Graph interaction boundaries (The drawing area)
GRAPH_AREA_RECT = pygame.Rect(10, 10, 560, 420)

class Button:
    def __init__(self, x, y, w, h, text, is_primary=False, is_toggle=False):
        self.rect = pygame.Rect(x, y, w, h)
        self.base_text = text # Store original text for toggle
        self.text = text
        self.is_primary = is_primary
        self.is_toggle = is_toggle
        self.is_active = False
        self.hovered = False

    def draw(self, surf, font):
        # 1. Determine base state and colors
        is_pressed = self.is_toggle and self.is_active

        if is_pressed:
            # UI FIX: Use TOGGLE_ACTIVE for active toggle buttons
            base_color = TOGGLE_ACTIVE 
            border_color = TOGGLE_ACTIVE 
            text_color = TEXT_LIGHT
        elif self.is_primary:
            # Primary action buttons remain blue
            base_color = BUTTON_ACTIVE
            border_color = (41, 115, 169) # Darker blue for depth
            text_color = TEXT_LIGHT
        else: # Normal button
            base_color = BUTTON_NORMAL
            border_color = BUTTON_BORDER
            text_color = TEXT_DARK

        # 2. Apply hover effect
        if self.hovered and not is_pressed:
            if self.is_primary:
                base_color = BUTTON_PRIMARY_HOVER 
            else:
                base_color = BUTTON_HOVER 
        
        # 3. Draw Shadow/Border (creates the depth effect)
        if not is_pressed:
            border_rect = pygame.Rect(self.rect.left, self.rect.top + 2, self.rect.width, self.rect.height - 2)
            pygame.draw.rect(surf, border_color, border_rect, border_radius=BORDER_RADIUS)

        # 4. Draw main rectangle
        draw_rect = self.rect
        if is_pressed:
            draw_rect = pygame.Rect(self.rect.left, self.rect.top + 2, self.rect.width, self.rect.height - 2)
            
        pygame.draw.rect(surf, base_color, draw_rect, border_radius=BORDER_RADIUS)
        
        # 5. Draw text
        # If text has been dynamically changed (like Pause/Resume) use the current text
        txt = font.render(self.text, True, text_color)
        
        # Center the text within the drawn rectangle
        text_center = draw_rect.center
        surf.blit(txt, txt.get_rect(center=text_center))

    def update_hover(self, pos):
        self.hovered = self.rect.collidepoint(pos)

    def clicked(self, pos):
        return self.rect.collidepoint(pos)

class GraphVisualizer:
    def __init__(self, nodes, edges):
        self.nodes = nodes # dict: id -> (x,y)
        self.edges = edges # list of (u,v)
        self.node_colors = {n: SECONDARY_ACCENT for n in nodes}
        self.is_running = False
        self.is_paused = False
        self.is_step_mode = False 
        self.steps = []
        self.current_index = 0
        self.interval = 700 
        self.last_time = 0
        
        self.next_node_id = 1 + max(self.nodes.keys(), default=0)
        self.temp_edge_start = None 

    def find_node_at(self, pos):
        """Returns the node ID at the given (x,y) position or None."""
        x, y = pos
        for nid, (nx, ny) in self.nodes.items():
            if math.hypot(nx - x, ny - y) <= NODE_RADIUS:
                return nid
        return None
        
    def add_node(self, pos):
        """Adds a new node at pos and returns its ID."""
        if not GRAPH_AREA_RECT.collidepoint(pos):
            return
        new_id = self.next_node_id
        self.nodes[new_id] = pos
        self.node_colors[new_id] = SECONDARY_ACCENT
        self.next_node_id += 1
        return new_id
        
    def add_edge(self, u, v):
        """Adds a directed edge (u, v) if it doesn't already exist."""
        if u != v and (u, v) not in self.edges:
            self.edges.append((u, v))
            
    def clear_graph(self):
        """Resets nodes and edges."""
        self.nodes = {}
        self.edges = []
        self.node_colors = {}
        self.next_node_id = 1
        self.reset() 

    def draw(self, surf, font, mouse_pos=None):
        # graph background
        pygame.draw.rect(surf, GRAPH_BG, GRAPH_AREA_RECT, border_radius=BORDER_RADIUS)
        pygame.draw.rect(surf, PRIMARY_DARK, GRAPH_AREA_RECT, 2, border_radius=BORDER_RADIUS)

        # Draw temporary edge if one is being created
        if self.temp_edge_start is not None and mouse_pos is not None:
            x1, y1 = self.nodes[self.temp_edge_start]
            self.draw_edge(surf, self.temp_edge_start, None, start_pos=(x1,y1), end_pos=mouse_pos, color=EDGE_TEMP)

        # edges
        for u,v in self.edges:
            self.draw_edge(surf, u, v)
            
        # nodes
        for nid,(x,y) in self.nodes.items():
            # Highlight the starting node of a temporary edge
            is_temp_start = (self.temp_edge_start == nid)
            self.draw_node(surf, font, nid, x, y, is_temp_start)

    def draw_node(self, surf, font, nid, x, y, is_temp_start=False):
        c = self.node_colors.get(nid, SECONDARY_ACCENT)
        # Main circle fill
        pygame.draw.circle(surf, c, (x,y), NODE_RADIUS)
        
        # Outline: Thicker and different color for the edge start selection
        outline_color = PRIMARY_DARK
        outline_width = 2
        if is_temp_start:
            outline_color = EDGE_TEMP
            outline_width = 4
            
        pygame.draw.circle(surf, outline_color, (x,y), NODE_RADIUS, outline_width)
        
        # Text
        text_color = TEXT_LIGHT
        txt = font.render(str(nid), True, text_color)
        surf.blit(txt, txt.get_rect(center=(x,y)))

    def draw_edge(self, surf, u, v, start_pos=None, end_pos=None, color=PRIMARY_DARK):
        if start_pos and end_pos:
            x1, y1 = start_pos
            x2, y2 = end_pos
            # For temporary edges, don't adjust to circumference
            adj_start_end = False
        else:
            x1,y1 = self.nodes[u]
            x2,y2 = self.nodes[v]
            adj_start_end = True
            
        dx,dy = x2-x1, y2-y1
        dist = math.hypot(dx,dy) or 1
        
        if adj_start_end:
            # Adjust line start/end to node circumference
            x1_adj = x1 + (dx/dist)*NODE_RADIUS
            y1_adj = y1 + (dy/dist)*NODE_RADIUS
            x2_adj = x2 - (dx/dist)*NODE_RADIUS
            y2_adj = y2 - (dy/dist)*NODE_RADIUS
        else:
            x1_adj, y1_adj, x2_adj, y2_adj = x1, y1, x2, y2

        # Draw line
        pygame.draw.line(surf, color, (x1_adj,y1_adj),(x2_adj,y2_adj), 2)
        
        # Draw arrowhead
        angle = math.atan2(dy,dx)
        arrow = 8
        px = x2_adj - math.cos(angle)*arrow * 0.5 # Arrow base back a bit
        py = y2_adj - math.sin(angle)*arrow * 0.5
        p1 = (px + math.cos(angle+2.4)*arrow, py + math.sin(angle+2.4)*arrow)
        p2 = (x2_adj, y2_adj)
        p3 = (px + math.cos(angle-2.4)*arrow, py + math.sin(angle-2.4)*arrow)
        pygame.draw.polygon(surf, color, [p1,p2,p3])

    def set_steps(self, steps, is_step_mode=False, interval_ms=700): 
        self.steps = steps
        self.current_index = 0
        self.interval = interval_ms
        self.is_step_mode = is_step_mode
        self.last_time = pygame.time.get_ticks()
        self.is_running = True
        self.is_paused = is_step_mode # Auto-pause if in step mode
        for n in self.node_colors:
            self.node_colors[n] = SECONDARY_ACCENT

    def advance_step(self): 
        if not self.is_running or self.current_index >= len(self.steps):
            return
            
        node, state = self.steps[self.current_index]
        self.node_colors[node] = state
        self.current_index += 1
        
        if self.current_index >= len(self.steps):
             self.is_running = False
             self.is_paused = False 

    def update(self):
        if self.is_step_mode:
            return 
            
        if not self.is_running or self.is_paused:
            self.last_time = pygame.time.get_ticks()
            return

        now = pygame.time.get_ticks()
        if now - self.last_time >= self.interval:
            self.advance_step() 
            self.last_time = now

    def reset(self):
        self.is_running = False
        self.is_paused = False
        self.is_step_mode = False 
        self.steps = []
        self.current_index = 0
        self.temp_edge_start = None
        for n in self.node_colors:
            self.node_colors[n] = SECONDARY_ACCENT

# Topological algorithms 
def topological_sort_dfs(graph, nodes):
    """
    Performs DFS for topological sort, ensuring all components are traversed 
    even after a cycle is detected, for complete visualization.
    Returns: (steps, is_cyclic)
    """
    visited = set()         # Nodes that have started DFS traversal
    recursion_stack = set() # Nodes currently in recursion stack (processing)
    steps = []
    is_cyclic = False
    
    # Sort nodes by ID to ensure deterministic starting order across components
    sorted_nodes = sorted(list(nodes)) 
    
    # DFS helper function
    def dfs(u):
        nonlocal is_cyclic
        
        visited.add(u)
        recursion_stack.add(u)
        steps.append((u, PROCESSING_COLOR))
        
        # Ensure all neighbors are processed
        for v in graph.get(u, []):
            if v in recursion_stack:
                # Back edge detected: Cycle!
                is_cyclic = True 
            if v not in visited:
                dfs(v)
            
        recursion_stack.remove(u)
        steps.append((u, VISITED_COLOR))
        
    for u in sorted_nodes:
        if u not in visited:
            dfs(u)
            
    return steps, is_cyclic 

def topological_sort_kahn(graph, nodes, edges):
    # This requires reconstructing adj list and in-degree from edges
    in_deg = {n:0 for n in nodes}
    adj = defaultdict(list)
    
    # Build adj list and in-degree
    for u,v in edges:
        if v in in_deg:
            adj[u].append(v)
            in_deg[v] += 1
        
    # Start with nodes that have zero in-degree, sorted for consistency
    q = deque(sorted([n for n in nodes if in_deg[n]==0]))
    
    steps = []
    result = []
    
    while q:
        u = q.popleft()
        
        # Two steps for visualization: start processing, then finish processing
        steps.append((u, PROCESSING_COLOR)) 
        result.append(u) # The actual result is built here
        
        # Process neighbors
        for v in adj[u]:
            in_deg[v] -= 1
            if in_deg[v]==0:
                q.append(v)
        
        steps.append((u, VISITED_COLOR))
        
    # Cycle detected if not all nodes were included in the topological order
    is_cyclic = (len(result) != len(nodes))
    
    return steps, is_cyclic

class TopologicalSortApp:
    # --- Mode Constants ---
    MODE_SELECT = "SELECT"
    MODE_NODE = "CREATE_NODE"
    MODE_EDGE = "CREATE_EDGE"
    MODE_RUNNING = "RUNNING"
    
    def __init__(self):
        pygame.init()
        self.width, self.height = 900, 600
        self.screen = pygame.display.set_mode((self.width, self.height))
        pygame.display.set_caption("Topological Sort Visualizer")
        self.clock = pygame.time.Clock()

        # fonts
        self.font_title = pygame.font.SysFont('Arial', 32, bold=True)
        self.font_medium = pygame.font.SysFont('Arial', 20)
        self.font_small = pygame.font.SysFont('Arial', 16)

        # Initial graph (starting empty)
        self.nodes = {}
        self.edges = []
        
        self.visualizer = GraphVisualizer(self.nodes, self.edges)
        self.current_algo = "DFS"
        self.topo_result = []

        self.cycle_detected = False
        self.step_mode_active = False 
        
        self.mode = self.MODE_NODE 
        
        # --- Buttons Positions ---
        bx1, by = 30, 450
        
        # Tool Toggles (Manual Creation)
        self.buttons = {
            "select_mode": Button(bx1, by, 80, 40, "Select", is_toggle=True),
            "create_node": Button(bx1 + 90, by, 80, 40, "Add Node", is_toggle=True),
            "create_edge": Button(bx1 + 180, by, 80, 40, "Add Edge", is_toggle=True),
        }
        self.buttons["create_node"].is_active = True
        
        # Graph Controls
        bx2 = bx1 + 280
        self.buttons.update({
             "clear_graph": Button(bx2, by, 100, 40, "Clear Graph", is_primary=True),
        })

        # Algorithm Toggles
        by_c = by + 50
        self.buttons.update({
            "dfs": Button(bx1, by_c, 80, 40, "DFS", is_toggle=True),
            "kahn": Button(bx1 + 90, by_c, 90, 40, "Kahn's", is_toggle=True),
        })
        self.buttons["dfs"].is_active = True
        
        # Simulation Controls
        bx3 = bx1 + 190
        self.buttons.update({
            "run": Button(bx3, by_c, 80, 40, "Run", is_primary=True),
            "pause": Button(bx3 + 90, by_c, 100, 40, "Pause", is_toggle=True), # Pause is now a toggle
            "reset": Button(bx3 + 200, by_c, 90, 40, "Reset"),
        })
        
        # Step Mode & Step Button
        by_s = by_c + 50
        self.buttons.update({
            "step_mode_toggle": Button(bx1, by_s, 110, 40, "Step Mode", is_toggle=True),
            "step_forward": Button(bx1 + 120, by_s, 110, 40, "Step \u25B6", is_primary=True) 
        })
        self.buttons["step_forward"].is_active = False 

    def get_adj_list(self):
        """Converts current edges list to an adjacency list for the algorithms."""
        adj = defaultdict(list)
        for u, v in self.edges:
            adj[u].append(v)
        return adj
        
    def run_algorithm(self):
        if self.visualizer.is_running and not self.visualizer.is_paused:
            return
            
        if not self.visualizer.nodes:
            print("Cannot run simulation: Graph is empty.")
            return
            
        self.visualizer.reset()
        self.topo_result = []
        self.cycle_detected = False
        
        graph_adj = self.get_adj_list()
        nodes_keys = self.visualizer.nodes.keys()
        
        if self.current_algo == "DFS":
            steps, is_cyclic = topological_sort_dfs(graph_adj, nodes_keys)
        else:
            steps, is_cyclic = topological_sort_kahn(graph_adj, nodes_keys, self.edges)

        if is_cyclic:
            self.cycle_detected = True
            
        self.visualizer.set_steps(steps, is_step_mode=self.step_mode_active, interval_ms=700)
        self.mode = self.MODE_RUNNING 
        self.update_mode_buttons()
        
        self.buttons["step_forward"].is_active = self.visualizer.is_step_mode and self.visualizer.is_running
        self.buttons["pause"].is_active = self.visualizer.is_paused # Activate pause toggle if in step mode
        self.update_pause_text()


    def set_mode(self, new_mode):
        """Changes the current application mode."""
        if self.visualizer.is_running:
            return 
            
        self.mode = new_mode
        self.visualizer.temp_edge_start = None 
        self.update_mode_buttons()
        
    def update_mode_buttons(self):
        """Sets the active state for the mode buttons based on self.mode."""
        self.buttons["select_mode"].is_active = (self.mode == self.MODE_SELECT)
        self.buttons["create_node"].is_active = (self.mode == self.MODE_NODE)
        self.buttons["create_edge"].is_active = (self.mode == self.MODE_EDGE)
        
    # NEW: Function to dynamically change Pause/Resume button text
    def update_pause_text(self):
        if self.visualizer.is_paused and self.visualizer.is_running and not self.visualizer.is_step_mode:
            self.buttons["pause"].text = "Resume"
        else:
            self.buttons["pause"].text = "Pause"
        
    def handle_graph_area_click(self, pos):
        """Handles mouse clicks inside the main graph drawing area."""
        
        clicked_node_id = self.visualizer.find_node_at(pos)

        if self.mode == self.MODE_NODE:
            if clicked_node_id is None:
                self.visualizer.add_node(pos)

        elif self.mode == self.MODE_EDGE:
            if clicked_node_id is not None:
                if self.visualizer.temp_edge_start is None:
                    self.visualizer.temp_edge_start = clicked_node_id
                else:
                    u = self.visualizer.temp_edge_start
                    v = clicked_node_id
                    self.visualizer.add_edge(u, v)
                    self.visualizer.temp_edge_start = None 
            else:
                self.visualizer.temp_edge_start = None
                
        elif self.mode == self.MODE_SELECT:
            pass 

    def handle_events(self):
        mouse_pos = pygame.mouse.get_pos()
        for ev in pygame.event.get():
            if ev.type == pygame.QUIT:
                pygame.quit(); sys.exit()
                
            elif ev.type == pygame.MOUSEMOTION:
                for b in self.buttons.values():
                    b.update_hover(mouse_pos)
            
            elif ev.type == pygame.MOUSEBUTTONDOWN and ev.button==1:
                pos = ev.pos
                
                if GRAPH_AREA_RECT.collidepoint(pos) and not self.visualizer.is_running:
                    self.handle_graph_area_click(pos)
                    continue

                # --- Tool Toggles ---
                if self.buttons["select_mode"].clicked(pos):
                    self.set_mode(self.MODE_SELECT)
                elif self.buttons["create_node"].clicked(pos):
                    self.set_mode(self.MODE_NODE)
                elif self.buttons["create_edge"].clicked(pos):
                    self.set_mode(self.MODE_EDGE)
                
                # --- Graph Controls ---
                elif self.buttons["clear_graph"].clicked(pos):
                    self.visualizer.clear_graph()
                    self.topo_result = []
                    self.cycle_detected = False
                    self.set_mode(self.MODE_NODE) 

                # --- Algorithm Toggles ---
                elif self.buttons["dfs"].clicked(pos):
                    self.current_algo = "DFS"
                    self.buttons["dfs"].is_active = True
                    self.buttons["kahn"].is_active = False
                    self.visualizer.reset()
                    self.topo_result = []
                    self.cycle_detected = False
                elif self.buttons["kahn"].clicked(pos):
                    self.current_algo = "Kahn's"
                    self.buttons["kahn"].is_active = True
                    self.buttons["dfs"].is_active = False
                    self.visualizer.reset()
                    self.topo_result = []
                    self.cycle_detected = False
                    
                # --- Simulation Controls ---
                elif self.buttons["run"].clicked(pos):
                    self.run_algorithm()
                
                # UI FIX: Pause/Resume logic simplified and handled by the toggle button
                elif self.buttons["pause"].clicked(pos) and self.visualizer.is_running and not self.visualizer.is_step_mode:
                    self.visualizer.is_paused = not self.visualizer.is_paused
                    self.buttons["pause"].is_active = self.visualizer.is_paused
                    if not self.visualizer.is_paused:
                        self.visualizer.last_time = pygame.time.get_ticks()
                    self.update_pause_text()

                elif self.buttons["reset"].clicked(pos):
                    self.visualizer.reset()
                    self.topo_result = []
                    self.cycle_detected = False
                    self.step_mode_active = False
                    self.buttons["step_mode_toggle"].is_active = False
                    self.buttons["step_forward"].is_active = False
                    self.buttons["pause"].is_active = False
                    self.update_pause_text()
                    self.set_mode(self.MODE_NODE) 
                    
                # --- Step Controls ---
                elif self.buttons["step_mode_toggle"].clicked(pos) and not self.visualizer.is_running:
                    self.step_mode_active = not self.step_mode_active
                    self.buttons["step_mode_toggle"].is_active = self.step_mode_active
                    self.buttons["step_forward"].is_active = False 
                
                elif self.buttons["step_forward"].clicked(pos) and self.visualizer.is_running and self.visualizer.is_step_mode:
                    self.visualizer.advance_step()
                    if not self.visualizer.is_running:
                         self.buttons["step_forward"].is_active = False


    def update_result_list(self):
        if not self.visualizer.steps and not self.visualizer.is_running and len(self.topo_result) == 0:
            return
            
        temp_result = []
        temp_result_set = set() 
        
        for i in range(self.visualizer.current_index):
            node, state = self.visualizer.steps[i]
            
            if self.current_algo == "DFS":
                if state == VISITED_COLOR and node not in temp_result_set:
                    temp_result.append(node)
                    temp_result_set.add(node)
                        
            elif self.current_algo == "Kahn's":
                if state == PROCESSING_COLOR and node not in temp_result_set:
                    temp_result.append(node)
                    temp_result_set.add(node)
        
        if self.current_algo == "DFS":
            self.topo_result = list(reversed(temp_result))
        else: 
            self.topo_result = temp_result
            
        if not self.visualizer.is_running and self.cycle_detected:
            self.topo_result = []


    def draw_info_panel(self):
        # right panel area 
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
        elif self.visualizer.is_paused and self.visualizer.is_running:
            # Check if simulation is finished (paused but current_index reached the end)
            if self.visualizer.current_index >= len(self.visualizer.steps) and len(self.visualizer.steps) > 0:
                 status_text = "Finished"
                 status_color = VISITED_COLOR
            else:
                 status_text = "Paused (Step Mode Active)" if self.visualizer.is_step_mode else "Paused"
                 status_color = PROCESSING_COLOR
        elif self.mode != self.MODE_SELECT and self.mode != self.MODE_RUNNING:
            status_text = f"Mode: {self.mode.replace('_', ' ').title()}"
            status_color = PRIMARY_DARK

        status_s = self.font_medium.render(f"Status: {status_text}", True, status_color)
        self.screen.blit(status_s, (rx+15, ty+58))
        
        algo = self.font_medium.render(f"Algorithm: {self.current_algo}", True, PRIMARY_DARK)
        self.screen.blit(algo, (rx+15, ty+88))

        # Current step (more concise)
        if self.visualizer.steps:
            progress_percent = int((self.visualizer.current_index / len(self.visualizer.steps)) * 100) if len(self.visualizer.steps) > 0 else 0
            step_txt = self.font_medium.render(f"Progress: {self.visualizer.current_index}/{len(self.visualizer.steps)} steps ({progress_percent}%)", True, PRIMARY_DARK)
            self.screen.blit(step_txt, (rx+15, ty+118))
        else:
            step_txt = self.font_medium.render(f"Nodes: {len(self.visualizer.nodes)}, Edges: {len(self.visualizer.edges)}", True, PRIMARY_DARK)
            self.screen.blit(step_txt, (rx+15, ty+118))
        
        
        # --- Section 2: Result List ---
        ry_res = ty + 160
        result_txt = self.font_medium.render("Topological Order:", True, PRIMARY_DARK)
        self.screen.blit(result_txt, (rx+15, ry_res))
        
        # Display Result
        self.update_result_list()
        res_s = " \u2192 ".join(map(str,self.topo_result)) if self.topo_result else "..."
        
        is_cycle_detected = self.cycle_detected and not self.visualizer.is_running
        
        if is_cycle_detected:
            if len(self.visualizer.nodes) > 0: 
                res_s = "Cycle Detected! \u274C"
                res_render = self.font_medium.render(res_s, True, PROCESSING_COLOR) 
        
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
        
        desc = ("DFS: post-order traversal using three states (unvisited, processing, visited) to detect cycles. O(V+E)"
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
                y += 20 
                line = w
            else:
                line = test
        if line:
            self.screen.blit(self.font_small.render(line, True, PRIMARY_DARK), (rx+15, y))
            y += 22
            
        # --- Section 4: Legend ---
        ry_legend = y + 20
        self.screen.blit(self.font_medium.render("Legend:", True, PRIMARY_DARK), (rx+15, ry_legend))
        
        # Draw legend items
        legend_items = [
            ("Unvisited", SECONDARY_ACCENT),
            ("Processing", PROCESSING_COLOR),
            ("Visited", VISITED_COLOR),
            ("Temp Edge", EDGE_TEMP)
        ]
        
        ly = ry_legend + 30
        
        for i, (text, color) in enumerate(legend_items):
            lx = rx + 15 
            
            # Draw circle/square for color reference
            if text == "Temp Edge":
                 pygame.draw.rect(self.screen, color, (lx+2, ly+4, 16, 8)) 
                 pygame.draw.rect(self.screen, PRIMARY_DARK, (lx+2, ly+4, 16, 8), 1)
            else:
                pygame.draw.circle(self.screen, color, (lx+10, ly+8), 8)
                
            self.screen.blit(self.font_small.render(text, True, PRIMARY_DARK), (lx+30, ly))
            ly += 25


    def draw(self):
        self.screen.fill(BACKGROUND_COLOR)
        mouse_pos = pygame.mouse.get_pos()
        self.visualizer.draw(self.screen, self.font_medium, mouse_pos)
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