package com.urnadigital.eleitor;

import javax.swing.SwingUtilities;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TelaVotacao().setVisible(true));
    }
}
