import java.util.ArrayList;
import java.util.Scanner;

public class Activity6_1 {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);

        System.out.print("Enter how many numbers: ");
        int n = userInput.nextInt();
        int[] numbers = new int[n];

        // Lists for odd and even numbers
        ArrayList<Integer> evenList = new ArrayList<>();
        ArrayList<Integer> oddList = new ArrayList<>();

        System.out.println("Enter the numbers:");
        for (int i = 0; i < n; i++) {
            numbers[i] = userInput.nextInt();

            if (numbers[i] % 2 == 0) {
                evenList.add(numbers[i]);
            } else {
                oddList.add(numbers[i]);
            }
        }

        System.out.println("Even numbers list: " + evenList);
        System.out.println("Odd numbers list: " + oddList);
    }
}
