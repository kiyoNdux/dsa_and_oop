import javax.swing.JOptionPane;

class TwoDimensionArray{
	public static void main(String[] args) {
		String inp, str = "";
		int arr[][] = new int[2][3];
		
		for (int i=0; i<2; i++) {
			for (int j=0; j<3; j++) {
				inp=JOptionPane.showInputDialog(null, "Input value in Index["+i+"]["+j+"]:");
				arr[i][j]=Integer.parseInt(inp);
				str = str+"Index["+i+"]["+j+"]:" + arr[i][j]+"\n";
			}
		}

		JOptionPane.showMessageDialog(null,"Input values are:\n\n" + str);
	}
}