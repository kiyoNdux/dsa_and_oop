import javax.swing.*;

class MultiplicationTable{
	public static void main(String[] args) {
		int multp_arr[] = new int[100];
		int counter = -1;
		StringBuilder str = new StringBuilder();
		for(int i=1; i<=10; i++) {
			for(int j=1; j<=10; j++) {
				counter++;
				multp_arr[counter] = i*j;
				// System.out.print(i*j + " ");
			}
		}
		for (int k = 0; k < multp_arr.length; k++){
			str.append(String.format("%4d", multp_arr[k]));
			if ((k+1)%10 == 0) {
				str.append("\n");
			}
		}
		JOptionPane.showMessageDialog(null, str.toString(), "MULTIPLICATION TABLE", JOptionPane.INFORMATION_MESSAGE);
	}
}