package org.example;

import javax.swing.*;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ServidorTCP {

    public SessionMessage execute() {
        try {
            // Cria um socket para a porta 332, porém ainda fechada
            ServerSocket serverSocket = new ServerSocket(3322);
            JOptionPane.showMessageDialog(null, "Servidor TCP iniciado na porta 3322");

            SessionMessage sessionMessage = new SessionMessage();

            // Abre a porta 3322 para aceitar conexões
            Socket client = serverSocket.accept();

            ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());

            String msg = JOptionPane.showInputDialog("Digite a mensagem que deseja enviar para o cliente:");
            msg += "\n \n Seu IP é : " + client.getInetAddress().getHostAddress() + "\n \n Sua porta é : "
                    + client.getPort() + "\n \n Conexão estabelecida com sucesso!";
            writer.writeUTF(msg);

            sessionMessage.setMsg1(msg);

            writer.flush();// limpa lixo da conexão

            ObjectInputStream reader = new ObjectInputStream(client.getInputStream());

            JOptionPane.showMessageDialog(null, reader.readUTF());

            sessionMessage.setMsg2(reader.readUTF());

            reader.close();
            writer.close();
            client.close();
            serverSocket.close();

            return sessionMessage;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro no servidor:" + e.getMessage());
            return null;
        }
    }
}
