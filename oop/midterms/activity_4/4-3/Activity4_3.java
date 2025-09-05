import javax.swing.JOptionPane;

public class Activity4_3 {
    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Student Name:");
        String course = JOptionPane.showInputDialog("Course:");
        String year = JOptionPane.showInputDialog("Year Level:");

        double prelim = Double.parseDouble(JOptionPane.showInputDialog("Prelim Grade:"));
        double midterm = Double.parseDouble(JOptionPane.showInputDialog("Midterm Grade:"));
        double finals = Double.parseDouble(JOptionPane.showInputDialog("Final Grade:"));

        String prelimStr, midtermStr, finalsStr, averageStr, gradeEquivalent;

        // Validate prelim
        if (prelim >= 0 && prelim <= 100) prelimStr = String.format("%.1f", prelim);
        else prelimStr = "N/A";

        // Validate midterm
        if (midterm >= 0 && midterm <= 100) midtermStr = String.format("%.1f", midterm);
        else midtermStr = "N/A";

        // Validate finals
        if (finals >= 0 && finals <= 100) finalsStr = String.format("%.1f", finals);
        else finalsStr = "N/A";

        // Compute average only if all are valid
        if (prelimStr.equals("N/A") || midtermStr.equals("N/A") || finalsStr.equals("N/A")) {
            averageStr = "N/A";
            gradeEquivalent = "N/A";
        } else {
            double average = (prelim + midterm + finals) / 3.0;
            averageStr = String.format("%.2f", average);

            if (average >= 97 && average <= 100) gradeEquivalent = "1.00";
            else if (average >= 94) gradeEquivalent = "1.25";
            else if (average >= 91) gradeEquivalent = "1.50";
            else if (average >= 88) gradeEquivalent = "1.75";
            else if (average >= 85) gradeEquivalent = "2.00";
            else if (average >= 82) gradeEquivalent = "2.25";
            else if (average >= 79) gradeEquivalent = "2.50";
            else if (average >= 77) gradeEquivalent = "2.75";
            else if (average >= 75) gradeEquivalent = "3.00";
            else gradeEquivalent = "5.00";
        }

        // Match your requested format
        String message = String.format(
            "STUDENT NAME: %s\nCOURSE: %s\nYEAR LEVEL: %s\n\nGRADES\nPRELIM: %s\nMIDTERM: %s\nFINALS: %s\nAVERAGE: %s\nCONVERTED GRADE: %s",
            name, course, year, prelimStr, midtermStr, finalsStr, averageStr, gradeEquivalent
        );

        JOptionPane.showMessageDialog(null, message, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
