import javax.swing.JOptionPane;

class PassOrFail {
	public static void main(String[] args) {
		float grade;
		String name;

		name = JOptionPane.showInputDialog("What is your Name: ");
		grade = Float.parseFloat(JOptionPane.showInputDialog("What is your Grade: "));

		if (grade >= 75) {
			JOptionPane.showMessageDialog(null, "Name: " + name +" Status: passed.", "Message", JOptionPane.INFORMATION_MESSAGE);	
		} else {
			JOptionPane.showMessageDialog(null, "Name: " + name + "Status: failed.", "Message", JOptionPane.INFORMATION_MESSAGE);	
		}
	}
}