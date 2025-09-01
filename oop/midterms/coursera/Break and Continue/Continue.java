public class Continue{
    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            if (i == 5) {
                System.out.println("Skipping number 5.");
                continue; // Skip the rest of the loop when i is 5
            }
            System.out.println("Number: " + i);
        }

        System.out.println("Loop has ended.");
    }
}