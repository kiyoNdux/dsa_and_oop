import javax.swing.JOptionPane;

public class Activity4_2 {
    public static void main(String[] args) {
        double price = Double.parseDouble(JOptionPane.showInputDialog("Enter the price:"));

        double discountRate;
        if (price >= 0 && price <= 5000) {
            discountRate = 0.05;
        } else if (price <= 10000) {
            discountRate = 0.07;
        } else {
            discountRate = 0.10;
        }

        double discount = price * discountRate;
        double netPrice = price - discount;

        String message = String.format(
            "Original Price: %.2f\nDiscount Rate: %.0f%%\nDiscount: %.2f\nNew Price: %.2f",
            price, discountRate * 100, discount, netPrice
        );

        JOptionPane.showMessageDialog(null, message, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
