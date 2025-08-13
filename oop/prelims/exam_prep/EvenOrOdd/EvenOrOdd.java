import javax.swing.JOptionPane;

class EvenOrOdd {
	public static void main(String[] args) {
		int number;

		number = Integer.parseInt(JOptionPane.showInputDialog("Type your number: "));
		if (number%2==0) {
			JOptionPane.showMessageDialog(null, "your number is even", "Odd or Even", JOptionPane.INFORMATION_MESSAGE);
		} else {
			JOptionPane.showMessageDialog(null, "your number is odd", "Odd or Even", JOptionPane.INFORMATION_MESSAGE);
		}
	}

}