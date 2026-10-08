package com.urna;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import javax.swing.JOptionPane;

public class Urna {

    private final String multicastIp = "239.0.0.10";
    private final int port = 6668;

    public void execute() {
        try {
            List<Integer> votos = new ArrayList<>(List.of(0, 0, 0));
            while (somarVotos(votos)) {
                Integer voto = receberVoto();
                votos.set(voto-1, votos.get(voto-1) + 1);
            }
            enviarResultadoMultiCast(votos);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro no servidor:" + e.getMessage());
        }
    }

    private boolean somarVotos(List<Integer> votos) {
        Integer qntdVotos = votos.stream().mapToInt(Integer::intValue)
                .sum();
        if (qntdVotos >= 3) {
            return false;
        }
        return true;
    }

    public Integer receberVoto() {
        try {
            // Cria um socket para a porta 332, porém ainda fechada
            ServerSocket serverSocket = new ServerSocket(3322);
            JOptionPane.showMessageDialog(null, "Servidor TCP iniciado na porta 3322");
            Integer candidato = 0;
            // Abre a porta 3322 para aceitar conexões
            Socket client = serverSocket.accept();

            // Espera com que a urna envie o numero do candidato escolhido
            ObjectInputStream reader = new ObjectInputStream(client.getInputStream());

            candidato = reader.readInt();
            JOptionPane.showMessageDialog(null, "Candidato selecionado: " + candidato.toString());

            ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());

            writer.writeUTF(multicastIp);

            writer.flush();// limpa lixo da conexão

            reader.close();
            writer.close();
            client.close();
            serverSocket.close();
            return candidato;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro no servidor:" + e.getMessage());
            return 0;
        }
    }

    private void enviarResultadoMultiCast(List<Integer> votos) {
        try (DatagramSocket ds = new DatagramSocket()) {
            InetAddress ipAddress = InetAddress.getByName(multicastIp);
            byte[] b = ("O candidato ganhador foi: "+ ganhador(votos)).getBytes();

            DatagramPacket dp = new DatagramPacket(b, b.length, ipAddress, port);
            ds.send(dp);

            System.out.println("Mensagem enviada a: " + ipAddress.getHostAddress() + " na porta: " + port);

            ds.close();
        } catch (Exception e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Erro no emissor: " + e.getMessage());
        }
    }

    private String ganhador(List<Integer> votos) {
        return String.valueOf(votos.indexOf(Collections.max(votos)) + 1);
    }

}
