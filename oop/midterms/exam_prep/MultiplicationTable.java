import javax.swing.*;

class MultiplicationTable{
	public static void main(String[] args) {
		int multp_arr[] = new int[100];
		int counter = -1;
		String str="";
		for(int i=1; i<=10; i++) {
			for(int j=1; j<=10; j++) {
				counter++;
				multp_arr[counter] = i*j;
				// System.out.print(i*j + " ");
			}
		}
		for (int k = 0; k < multp_arr.length; k++){
			str = str + multp_arr[k] + " ";
			if ((k+1)%10 == 0) {
				str = str + "\n";
			}
		}
		JOptionPane.showMessageDialog(null, str);
	}
}