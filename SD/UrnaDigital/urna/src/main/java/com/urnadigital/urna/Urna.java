package com.urnadigital.urna;

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

    private static final String[] CANDIDATOS = { "Ana Souza", "Bruno Lima", "Carla Mendes" };

    public static final int VOTO_BRANCO = 4;
    public static final int VOTO_NULO = 5;

    private static final int NUM_VOTOS_ESPERADOS = 3;

    private final String multicastIp = "239.0.0.10";
    private final int port = 6668;

    public void execute() {
        try {
            // Índices 0..2 = candidatos, 3 = branco, 4 = nulo
            List<Integer> votos = new ArrayList<>(List.of(0, 0, 0, 0, 0));
            while (somarVotos(votos) < NUM_VOTOS_ESPERADOS) {
                Integer voto = receberVoto();
                int indice = indiceDoVoto(voto);
                votos.set(indice, votos.get(indice) + 1);
            }
            enviarResultadoMultiCast(votos);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro no servidor:" + e.getMessage());
        }
    }

    private int somarVotos(List<Integer> votos) {
        return votos.stream().mapToInt(Integer::intValue).sum();
    }

    private int indiceDoVoto(int voto) {
        if (voto == VOTO_BRANCO) {
            return 3;
        }
        if (voto == VOTO_NULO) {
            return 4;
        }
        return voto - 1;
    }

    public Integer receberVoto() {
        try {
            // Cria um socket para a porta 3322, porém ainda fechada
            ServerSocket serverSocket = new ServerSocket(3322);
            //JOptionPane.showMessageDialog(null, "Servidor TCP iniciado na porta 3322");
            Integer voto = 0;
            // Abre a porta 3322 para aceitar conexões
            Socket client = serverSocket.accept();

            // Espera com que a urna envie o voto do eleitor
            ObjectInputStream reader = new ObjectInputStream(client.getInputStream());

            voto = reader.readInt();
            JOptionPane.showMessageDialog(null, "Voto recebido: " + descricaoVoto(voto));

            ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());

            writer.writeUTF(multicastIp);

            writer.flush();// limpa lixo da conexão

            reader.close();
            writer.close();
            client.close();
            serverSocket.close();
            return voto;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro no servidor:" + e.getMessage());
            return 0;
        }
    }

    private String descricaoVoto(int voto) {
        if (voto == VOTO_BRANCO) {
            return "Branco";
        }
        if (voto == VOTO_NULO) {
            return "Nulo";
        }
        return CANDIDATOS[voto - 1];
    }

    private void enviarResultadoMultiCast(List<Integer> votos) {
        try (DatagramSocket ds = new DatagramSocket()) {
            InetAddress ipAddress = InetAddress.getByName(multicastIp);
            byte[] b = montarResultado(votos).getBytes();

            DatagramPacket dp = new DatagramPacket(b, b.length, ipAddress, port);
            ds.send(dp);

            System.out.println("Mensagem enviada a: " + ipAddress.getHostAddress() + " na porta: " + port);

            ds.close();
        } catch (Exception e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Erro no emissor: " + e.getMessage());
        }
    }

    private String montarResultado(List<Integer> votos) {
        StringBuilder sb = new StringBuilder();
        sb.append("Resultado da apuração:\n");
        for (int i = 0; i < CANDIDATOS.length; i++) {
            sb.append(CANDIDATOS[i]).append(": ").append(votos.get(i)).append(" voto(s)\n");
        }
        sb.append("Branco: ").append(votos.get(3)).append(" voto(s)\n");
        sb.append("Nulo: ").append(votos.get(4)).append(" voto(s)\n");
        sb.append("\nO candidato ganhador foi: ").append(ganhador(votos));
        return sb.toString();
    }

    private String ganhador(List<Integer> votos) {
        List<Integer> votosCandidatos = votos.subList(0, CANDIDATOS.length);
        return CANDIDATOS[votosCandidatos.indexOf(Collections.max(votosCandidatos))];
    }

}
