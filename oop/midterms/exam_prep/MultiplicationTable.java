import javax.swing.*;
import java.awt.*;

public class MultiplicationTable {
    public static void main(String[] args) {
        JPanel panel = new JPanel(new GridLayout(10, 10, 5, 5));

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                JLabel label = new JLabel(String.valueOf(i * j), SwingConstants.CENTER);
                panel.add(label);
            }
        }

        JOptionPane.showMessageDialog(
            null,
            panel,
            "MULTIPLICATION TABLE",
            JOptionPane.INFORMATION_MESSAGE
        );
    }
}
