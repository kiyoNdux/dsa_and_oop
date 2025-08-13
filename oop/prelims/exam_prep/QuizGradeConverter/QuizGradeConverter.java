import javax.swing.JOptionPane;

class QuizGradeConverter {
	public static void main(String[] args) {
		double score;
		double totalGrade;
		
		score = Integer.parseInt(JOptionPane.showInputDialog("Enter your grade: "));
		totalGrade = (score/25)*50+50;
		
		JOptionPane.showMessageDialog(null, "Your Grade is: " + totalGrade, "Message", JOptionPane.INFORMATION_MESSAGE);
	}
}