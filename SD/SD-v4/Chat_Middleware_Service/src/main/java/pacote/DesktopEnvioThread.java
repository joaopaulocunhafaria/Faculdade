package pacote;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.JOptionPane;

public class DesktopEnvioThread implements Runnable{
    private volatile boolean paradaManual = false;
    private ServerSocket emissor;
    private Socket cliente;
    @Override
    public void run() {
        //throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
        try {
            while(!paradaManual){
                String msgs = "";
                // Antes da primeira mensagem o arquivo ainda não existe: envia histórico vazio
                if(new File(Util.PathRepDesktop).exists()){
                    FileReader freader = new FileReader(Util.PathRepDesktop);
                    BufferedReader buffer = new BufferedReader(freader);
                    while(buffer.ready()){
                        msgs += buffer.readLine();
                    }    
                    buffer.close();
                    freader.close();
                }
                // setReuseAddress precisa vir antes do bind para permitir religar o serviço
                emissor = new ServerSocket();
                emissor.setReuseAddress(true);
                emissor.bind(new InetSocketAddress(Util.PortaEnvioDesktop));
                cliente = emissor.accept();
                ObjectOutputStream output = new ObjectOutputStream(cliente.getOutputStream());
                output.writeUTF(msgs);
                output.close();
                cliente.close();
                emissor.close();
            }
        } catch (Exception e) {
            if(!paradaManual){
                JOptionPane.showMessageDialog(null,"Erro em Desktop Envio Thread:" + e.getMessage());
                e.printStackTrace();
            }
        }
    }
    public void fecharServidor(){
        paradaManual = true;
        try{
            if((cliente != null)&&(!cliente.isClosed())){
                cliente.close();
            } 
            if((emissor != null)&&(!emissor.isClosed())){
                emissor.close();
            }
        } catch (Exception e){
            JOptionPane.showMessageDialog(null,"Erro em DesktopEnvioThread::fecharServidor:\n"+ e.getMessage());
        }
    }
    
}
