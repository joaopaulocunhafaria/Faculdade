package com.receivermulticast;

import javax.swing.*;
import java.net.*;

public class Main {

    public static void main(String[] args) {

        try {

            final int port = 6668;
            InetAddress address = InetAddress.getByName("239.0.0.10");
            InetSocketAddress group = new InetSocketAddress(address, port);
            NetworkInterface netIf = NetworkInterface.getByName("wlp0s20f3");

            MulticastSocket s = new MulticastSocket(group.getPort());
            s.joinGroup(group, netIf);
            byte[] b = new byte[256];
            DatagramPacket pckt = new DatagramPacket(b, b.length);
            s.receive(pckt);
            JOptionPane.showMessageDialog(null, new String(b).trim());
            s.close();

        } catch (Exception e) {

            JOptionPane.showMessageDialog(null, "error:" + e.getMessage());

        }

    }

}