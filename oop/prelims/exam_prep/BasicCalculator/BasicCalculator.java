import javax.swing.JOptionPane;

class BasicCalculator {
	public static void main(String[] args) {
		String operator;
		int operatorParse;
		float num1, num2;

		operator = JOptionPane.showInputDialog("Type an operator (+, -, *, /): ");
		num1 = Float.parseFloat(JOptionPane.showInputDialog("Type the first number: "));
		num2 = Float.parseFloat(JOptionPane.showInputDialog("Type the second number: "));

		if (operator.equals("+")) {
			JOptionPane.showMessageDialog(null, num1 + num2, "Message", JOptionPane.INFORMATION_MESSAGE);
		} else if (operator.equals("-")) {
			JOptionPane.showMessageDialog(null, num1 - num2, "Message", JOptionPane.INFORMATION_MESSAGE);
		} else if (operator.equals("*")) {
			JOptionPane.showMessageDialog(null, num1 * num2, "Message", JOptionPane.INFORMATION_MESSAGE);
		} else if (operator.equals("/")) {
			JOptionPane.showMessageDialog(null, num1 / num2, "Message", JOptionPane.INFORMATION_MESSAGE);
		} else {
			JOptionPane.showMessageDialog(null, "Please use the proper operator (+, -, *, /)", "Message", JOptionPane.INFORMATION_MESSAGE);
		}
	}
}