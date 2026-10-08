package org.example;

import javax.swing.*;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ClienteTCP {

    public void execute(){
        try {
            Socket client = new Socket("200.128.142.203", 3322);

            ObjectInputStream reader = new ObjectInputStream( client.getInputStream());

            JOptionPane.showMessageDialog(null, reader.readUTF());
          

            ObjectOutputStream writer = new ObjectOutputStream(client.getOutputStream());
            
            String msg = JOptionPane.showInputDialog("Digite a mensagem que deseja enviar para o servidor:");
            writer.writeUTF(msg);
            writer.flush();//limpa lixo da conexão
            
            reader.close();
            writer.close();
            client.close();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null,"Erro ao conectar com o servidor:" + e.getMessage());
        }
    }
}
