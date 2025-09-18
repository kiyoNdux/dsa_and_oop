import javax.swing.*;

class SumOfDigits{
	public static void main(String[] args) {
		String input = JOptionPane.showInputDialog(null, "Input a number: ");
		int number = Integer.parseInt(input);

		int original = number;
		int sum = 0;
		String result = "Input number: " + original + "\n";
		result += "Individual numbers:\n";

		String digits = "";
		while (number>0) {
			int digit = number % 10; // get last digit
			sum += digit;
			digits = digit + "\n" + digits;
			number /= 10; // remove last digit
		}

		result += digits;
		result += "\nSUM: " + sum;

		JOptionPane.showMessageDialog(null, result, "Message", JOptionPane.INFORMATION_MESSAGE);
	}
}