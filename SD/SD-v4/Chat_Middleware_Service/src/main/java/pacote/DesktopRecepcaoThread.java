package pacote;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.JOptionPane;

public class DesktopRecepcaoThread implements Runnable {
    private volatile boolean paradaManual = false;
    private Socket cliente;
    private ServerSocket receptor;
    @Override
    public void run() {
        //throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
        try{
            while(!paradaManual){
                // setReuseAddress precisa vir antes do bind para permitir religar o serviço
                receptor = new ServerSocket();
                receptor.setReuseAddress(true);
                receptor.bind(new InetSocketAddress(Util.PortaRecepcaoDesktop));
                cliente = receptor.accept();
                ObjectInputStream reader = new ObjectInputStream(cliente.getInputStream());
                String msg = reader.readUTF();
                reader.close();
                cliente.close();
                receptor.close();
                FileWriter fwriter = new FileWriter(Util.PathRepDesktop,true);
                fwriter.write(msg);
                fwriter.write(System.lineSeparator());
                fwriter.close();
            }
        } catch (Exception e){
            if(!paradaManual){
                JOptionPane.showMessageDialog(null,"Erro em DesktopRecepcaoThread::run:\n"+e.getMessage());                
            }
        }
    }
    public void fecharServidor(){
        paradaManual = true;
        try{
            if((cliente != null)&&(!cliente.isClosed())){
                cliente.close();
            } 
            if((receptor != null)&&(!receptor.isClosed())){
                receptor.close();
            }
        } catch (Exception e){
            if(paradaManual){
                JOptionPane.showMessageDialog(null,"Erro em DesktopRecepcaoThread::fecharServidor:\n"+ e.getMessage());
            }         
        }
        
    }
    
    
}
