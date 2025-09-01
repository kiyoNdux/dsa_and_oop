public class Break{
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        for (int number : numbers) {
            if (number == 5) {
                System.out.println("Found 5, exiting the loop.");
                break; // Exit the loop when number is 5
            }
            System.out.println("Number: " + number);
        }

        System.out.println("Loop has ended.");
    }
}