import javax.swing.JOptionPane;

public class Activity4_1 {
    public static void main(String[] args) {
        int num = Integer.parseInt(JOptionPane.showInputDialog("Enter a number:"));

        String message;
        if (num >= 1 && num <= 100) {
            message = "Input number " + num + " is between 1 and 100.";
        } else {
            message = "Input number " + num + " is NOT between 1 and 100.";
        }

        JOptionPane.showMessageDialog(null, message, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
