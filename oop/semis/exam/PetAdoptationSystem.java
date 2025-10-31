private void styleTextFields() {
    javax.swing.JTextField[] textFields = {
        jTextField1, jTextField2, jTextField3, 
        jTextField4, jTextField5, jTextField6, jTextField7
    };

    java.awt.Font fieldFont = new java.awt.Font("Segoe UI", java.awt.Font.PLAIN, 14);
    javax.swing.border.Border textBorder = javax.swing.BorderFactory.createCompoundBorder(
        javax.swing.BorderFactory.createLineBorder(new java.awt.Color(204, 204, 204)),
        javax.swing.BorderFactory.createEmptyBorder(5, 7, 5, 7)
    );

    for (javax.swing.JTextField field : textFields) {
        field.setFont(fieldFont);
        field.setBorder(textBorder);
        field.setBackground(java.awt.Color.WHITE);
        field.setForeground(java.awt.Color.BLACK);
    }
}

private void styleComboBoxes() {
    javax.swing.JComboBox[] comboBoxes = {
        jComboBox1, jComboBox2
    };

    java.awt.Font comboFont = new java.awt.Font("Segoe UI", java.awt.Font.PLAIN, 14);
    javax.swing.border.Border comboBorder = javax.swing.BorderFactory.createCompoundBorder(
        javax.swing.BorderFactory.createLineBorder(new java.awt.Color(204, 204, 204)),
        javax.swing.BorderFactory.createEmptyBorder(2, 5, 2, 5)
    );

    for (javax.swing.JComboBox box : comboBoxes) {
        box.setFont(comboFont);
        box.setBorder(comboBorder);
        box.setBackground(java.awt.Color.WHITE);
        box.setForeground(java.awt.Color.BLACK);
        ((javax.swing.JComponent) box.getEditor().getEditorComponent()).setBorder(
            javax.swing.BorderFactory.createEmptyBorder(0, 3, 0, 0)
        );
    }
}