import java.util.Scanner;

class Agent {
    String name;
    double[] sales;

    // Constructor
    Agent(String name, double[] sales) {
        this.name = name;
        this.sales = sales;
    }

    // compute average sales
    double averageSales() {
        double sum = 0;
        for (double s : sales) {
            sum += s;
        }
        return sum / sales.length;
    }

    // get highest sale
    double highestSale() {
        double max = sales[0];
        for (double s : sales) {
            if (s > max) {
                max = s;
            }
        }
        return max;
    }
}

public class Activity6_3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of agents: ");
        int n = input.nextInt();
        input .nextLine();

        Agent[] agents = new Agent[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter agent name: ");
            String name = input.nextLine();

            System.out.print("Enter number of sales: ");
            int salesCount = input.nextInt();
            double[] sales = new double[salesCount];

            System.out.println("Enter sales values:");
            for (int j = 0; j < salesCount; j++) {
                sales[j] = input.nextDouble();
            }
            input.nextLine(); // consume newline

            agents[i] = new Agent(name, sales);
        }

        // Display averages and find best performer
        Agent topAgent = agents[0];
        for (Agent agent : agents) {
            System.out.println(agent.name + " -> Average Sales: " + agent.averageSales());
            if (agent.highestSale() > topAgent.highestSale()) {
                topAgent = agent;
            }
        }

        System.out.println("Agent with highest sale: " + topAgent.name +
                           " (Sale: " + topAgent.highestSale() + ")");
    }
}
