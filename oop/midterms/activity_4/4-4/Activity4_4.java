import javax.swing.JOptionPane;

public class Activity4_4 {
    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Student Name:");
        String course = JOptionPane.showInputDialog("Course:");
        int year;
        try {
            year = Integer.parseInt(JOptionPane.showInputDialog("Year Level (1-4):"));
            if (year < 1 || year > 4) {
                JOptionPane.showMessageDialog(null, "Error: Year level must be between 1 and 4.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                return;
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error: Invalid year level input.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            return;
        }

        int units;
        try {
            units = Integer.parseInt(JOptionPane.showInputDialog("Units Enrolled:"));
            if (units < 0) {
                JOptionPane.showMessageDialog(null, "Error: Units cannot be negative.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                return;
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error: Invalid units input.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            return;
        }

        int labSubjects;
        try {
            labSubjects = Integer.parseInt(JOptionPane.showInputDialog("Subjects with Laboratory:"));
            if (labSubjects < 0) {
                JOptionPane.showMessageDialog(null, "Error: Lab subjects cannot be negative.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                return;
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error: Invalid lab subjects input.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String modeInput = JOptionPane.showInputDialog("Mode of Payment (C for Cash, I for Installment):");
        if (modeInput == null || (!modeInput.equalsIgnoreCase("C") && !modeInput.equalsIgnoreCase("I"))) {
            JOptionPane.showMessageDialog(null, "Error: Payment mode must be C (Cash) or I (Installment).", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // constants
        final double MISCELLANEOUS = 3000.0;
        final double LAB_FEE_PER_SUBJECT = 800.0;

        double amountPerUnit = 0, downPayment = 0;
        switch (year) {
            case 1: amountPerUnit = 800; downPayment = 8000; break;
            case 2: amountPerUnit = 600; downPayment = 6000; break;
            case 3: amountPerUnit = 500; downPayment = 5000; break;
            case 4: amountPerUnit = 400; downPayment = 4000; break;
        }

        double labFee = labSubjects * LAB_FEE_PER_SUBJECT;
        double tuition = units * amountPerUnit;
        double totalFee = MISCELLANEOUS + labFee + tuition;

        StringBuilder sb = new StringBuilder();
        sb.append("Name: ").append(name).append("\n")
          .append("Course: ").append(course).append("\n")
          .append("Year Level: ").append(year).append("\n\n")
          .append("Units Enrolled: ").append(units).append("\n")
          .append("Amount Per Unit: ").append(String.format("%.2f", amountPerUnit)).append("\n")
          .append("Subject with Laboratory: ").append(labSubjects).append("\n\n");

        if (modeInput.equalsIgnoreCase("C")) {
            double discount = totalFee * 0.10;
            double netTotal = totalFee - discount;
            sb.append("MODE OF PAYMENT: CASH\n")
              .append("MISCELLANEOUS: ").append(String.format("%.2f", MISCELLANEOUS)).append("\n")
              .append("LABORATORY FEE: ").append(String.format("%.2f", labFee)).append("\n")
              .append("TUITION FEE: ").append(String.format("%.2f", tuition)).append("\n")
              .append("TOTAL FEE: ").append(String.format("%.2f", totalFee)).append("\n")
              .append("DISCOUNT: ").append(String.format("%.2f", discount)).append("\n")
              .append("TOTAL PAYMENT: ").append(String.format("%.2f", netTotal));
        } else {
            double remaining = totalFee - downPayment;
            double installment = remaining / 3.0;
            sb.append("MODE OF PAYMENT: INSTALLMENT\n")
              .append("MISCELLANEOUS: ").append(String.format("%.2f", MISCELLANEOUS)).append("\n")
              .append("LABORATORY FEE: ").append(String.format("%.2f", labFee)).append("\n")
              .append("TUITION FEE: ").append(String.format("%.2f", tuition)).append("\n")
              .append("TOTAL FEE: ").append(String.format("%.2f", totalFee)).append("\n")
              .append("DOWNPAYMENT: ").append(String.format("%.2f", downPayment)).append("\n")
              .append("PRELIM: ").append(String.format("%.2f", installment)).append("\n")
              .append("MIDTERM: ").append(String.format("%.2f", installment)).append("\n")
              .append("FINAL: ").append(String.format("%.2f", installment));
        }

        JOptionPane.showMessageDialog(null, sb.toString(), "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
