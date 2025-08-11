import javax.swing.JOptionPane;

class PassOrFail {
	public static void main(String[] args) {
		float grade;
		grade = Float.parseFloat(JOptionPane.showInputDialog("What is your Grade: "));

		if (grade >= 75) {
			JOptionPane.showMessageDialog(null, "You passed.", "Message", JOptionPane.INFORMATION_MESSAGE);	
		} else {
			JOptionPane.showMessageDialog(null, "You failed.", "Message", JOptionPane.INFORMATION_MESSAGE);	
		}
	}
}