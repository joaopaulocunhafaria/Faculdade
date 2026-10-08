package org.example;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {

        List<SessionMessage> messages = new ArrayList<SessionMessage>();
        ServidorTCP servidorTCP = new ServidorTCP();
        for (int i = 0; i < 2; i++) {
            messages.add(servidorTCP.execute());
        }

        String finalMessage = "";
        for (int i =0; i < messages.size(); i++) {
            finalMessage += "MSG "+i+": SRV → CLT: " + messages.get(i).getMsg1() + "\n";
            finalMessage += "MSG "+i+": CLT → SRV: " + messages.get(i).getMsg2() + "\n";
        }

        JOptionPane.showMessageDialog(null, finalMessage);
      
    }
}