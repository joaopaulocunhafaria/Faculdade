package com.eleitor;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.Socket;

import javax.swing.JOptionPane;

public class Eleitor {

    private final int port = 6668;

    public void execute() {
        try {
            Socket client = new Socket("127.0.0.1", 3322);

            ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());

            //Envia o voto
            String msg = JOptionPane.showInputDialog("Vote 1, 2 ou 3:");
            writer.writeInt(Integer.valueOf(msg));
            writer.flush();// limpa lixo da conexão


            ObjectInputStream reader = new ObjectInputStream(client.getInputStream());

            //Recebe o IP de Broadcast
            String broadcastIp = reader.readUTF();
            JOptionPane.showMessageDialog(null, "Endereço de Broadcast: "+ broadcastIp);

            //Começa a ouvir conexões UDP em broadcasto
            InetAddress address = InetAddress.getByName(broadcastIp);
            InetSocketAddress group = new InetSocketAddress(address, port);
            NetworkInterface netIf = NetworkInterface.getByName("wlp0s20f3");

            MulticastSocket s = new MulticastSocket(group.getPort());
            s.joinGroup(group, netIf);
            byte[] b = new byte[256];
            DatagramPacket pckt = new DatagramPacket(b, b.length);
            s.receive(pckt);
            JOptionPane.showMessageDialog(null, new String(b).trim());
            s.close();

            reader.close();
            writer.close();
            client.close();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro ao conectar com o servidor:" + e.getMessage());
        }
    }
}
