import javax.swing.JOptionPane;

class AgeQualification{
	public static void main (String[] args) {
		int age;
		age = Integer.parseInt(JOptionPane.showInputDialog("What is your age? "));

		if (age >= 18) {
			JOptionPane.showMessageDialog(null, "You are Eligible to vote", "Message", JOptionPane.INFORMATION_MESSAGE);
		} else {
			JOptionPane.showMessageDialog(null, "You are not Eligible to vote", "Message", JOptionPane.INFORMATION_MESSAGE);
			}
	}
}