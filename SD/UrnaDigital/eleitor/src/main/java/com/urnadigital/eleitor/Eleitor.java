package com.urnadigital.eleitor;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.net.Socket;

public class Eleitor {

    public static final int VOTO_BRANCO = 4;
    public static final int VOTO_NULO = 5;

    private final int port = 6668;

    /**
     * Envia o voto para a urna e aguarda, via multicast, o anúncio do resultado da apuração.
     */
    public String votar(int voto) throws Exception {
        Socket client = new Socket("127.0.0.1", 3322);

        ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());

        // Envia o voto
        writer.writeInt(voto);
        writer.flush();// limpa lixo da conexão

        ObjectInputStream reader = new ObjectInputStream(client.getInputStream());

        // Recebe o IP de Broadcast
        String broadcastIp = reader.readUTF();

        // Começa a ouvir conexões UDP em broadcast
        InetAddress address = InetAddress.getByName(broadcastIp);
        InetSocketAddress group = new InetSocketAddress(address, port);
        NetworkInterface netIf = NetworkInterface.getByName("wlp0s20f3");

        MulticastSocket s = new MulticastSocket(group.getPort());
        s.joinGroup(group, netIf);
        byte[] b = new byte[512];
        DatagramPacket pckt = new DatagramPacket(b, b.length);
        s.receive(pckt);
        String resultado = new String(b).trim();
        s.close();

        reader.close();
        writer.close();
        client.close();

        return resultado;
    }
}
