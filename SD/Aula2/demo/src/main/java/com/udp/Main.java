package com.udp;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {

        try {
            int port = 6666;
            DatagramSocket ds = new DatagramSocket(port);

            byte[] msg = new byte[256];

            DatagramPacket pckt = new DatagramPacket(msg, msg.length);

            ds.receive(pckt);
            ds.close();
            JOptionPane.showMessageDialog(null,new String(pckt.getData()).trim());

        } catch (Exception e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Erro ao receber: "+e.getMessage());
        }
    }
}