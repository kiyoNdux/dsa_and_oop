import javax.swing.JOptionPane;

class EmployeeType{
	public static void main(String[] args) {
		int employeeNumber;
		int partTime=1, fullTime=2;

		employeeNumber = Integer.parseInt(JOptionPane.showInputDialog("Give me your employee number: "));

		if (employeeNumber == partTime) {
			JOptionPane.showMessageDialog(null, "Parttimer", "Employee", JOptionPane.INFORMATION_MESSAGE);
		} else if (employeeNumber == fullTime) {
			JOptionPane.showMessageDialog(null, "Fulltimer", "Employee", JOptionPane.INFORMATION_MESSAGE);
		} else {
			JOptionPane.showMessageDialog(null, "Invalid Code", "Employee", JOptionPane.ERROR_MESSAGE);	
		}
	}
	
}