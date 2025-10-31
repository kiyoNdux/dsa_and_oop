private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
    // Clear all pets from the list and table
    petList.clear();
    if (petTableModel != null) {
        petTableModel.setRowCount(0);
    }

    // Remove all items from the Pet Name dropdown in Adoption Records
    jComboBox2.removeAllItems();

    // Clear input fields
    jTextField4.setText("");
    jTextField5.setText("");
    jTextField6.setText("");
    jComboBox1.setSelectedIndex(0);
    jTable1.clearSelection();

    JOptionPane.showMessageDialog(this, "All pets and input fields cleared.");
}//GEN-LAST:event_jButton4ActionPerformed