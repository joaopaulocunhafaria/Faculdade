package pacote;

import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.URL;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JTabbedPane;
import javax.swing.SwingUtilities;
import javax.swing.text.html.HTML;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.HTMLEditorKit;

public class FrmChat extends javax.swing.JFrame {
    public String msg = "";
    public void gerarEenviarMensagem(){
        this.msg = "";
        this.msg += "<img src='file:" + Util.avatar + "' width='20' height='20'>";
        //this.msg += "<font color='" + Util.cor + "'>";
        this.msg += "<font color='cor'> apelido </font>";
        this.msg = this.msg.replace("cor",Util.cor);
        this.msg = this.msg.replace("apelido",Util.nickname);
        if(CBModo.getSelectedItem().toString().equals("Fala")){
            this.msg += "<b> Fala: </b>";
            this.msg += TxtMensagem.getText();
        } else if(CBModo.getSelectedItem().toString().equals("Grita")){
            this.msg += "<b><i><u> Grita: </b></i></u>";
            this.msg += "<font color='Tomato' size='+1'>" + TxtMensagem.getText().toUpperCase();
        } else if(CBModo.getSelectedItem().toString().equals("Xinga")){
            this.msg += "<b> Xinga: </b>";
            this.msg += "<font color='Yellow' size='+3'>" + TxtMensagem.getText().toUpperCase();
        }
        this.msg += "<br>";
        ArrayList<String> codigos = new ArrayList<String>();
        ArrayList<String> simbolos = new ArrayList<String>();
        codigos.add(":-)");
        simbolos.add("&#128513");
        codigos.add(";-)");
        simbolos.add("&#128521");
        codigos.add(":-|");
        simbolos.add("&#128511");
        codigos.add(":-P");
        simbolos.add("&#128523");
        codigos.add(">:)");
        simbolos.add("&#128520");
        codigos.add("B-)");
        simbolos.add("&#128526");
        codigos.add(":-(");
        simbolos.add("&#128531");
        for(int i=0;i<codigos.size();i++){
            this.msg = this.msg.replace(codigos.get(i),simbolos.get(i));
        }
        try{
            Socket cliente = new Socket();
            cliente.connect(new InetSocketAddress("200.128.142.91",6662), 2000); // timeout para não travar se a máquina do servidor estiver fora
            ObjectOutputStream output = new ObjectOutputStream(cliente.getOutputStream());
            output.writeUTF(this.msg);
            output.close();
            cliente.close();
        } catch (IOException e) {
            // Servidor parado: mostra o aviso no painel em vez de dar erro
            this.entrarModoManutencao();
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null,"Erro no Cliente ao enviar:" + e.getMessage());
            e.printStackTrace();
        }
    }

    // Troca os tokens [emoji:Nome] e [gif:Nome] pelas imagens locais deste cliente.
    // (?i) porque os modos Grita/Xinga deixam o texto em maiúsculas.
    public String renderizarTokens(String html){
        for(String nome : Util.emojis){
            URL url = getClass().getResource("/images/emojis/" + nome + ".png");
            if(url != null){
                html = html.replaceAll("(?i)\\[emoji:" + Pattern.quote(nome) + "\\]",
                        Matcher.quoteReplacement("<img src='" + url + "' width='24' height='24'>"));
            }
        }
        for(String nome : Util.gifs){
            URL url = getClass().getResource("/images/gifs/" + nome + ".gif");
            if(url != null){
                html = html.replaceAll("(?i)\\[gif:" + Pattern.quote(nome) + "\\]",
                        Matcher.quoteReplacement("<img src='" + url + "' width='80'>"));
            }
        }
        return html;
    }

    private void montarPopupEmojis(){
        PopEmojis = new JPopupMenu();
        JTabbedPane abas = new JTabbedPane();
        JPanel pnlEmojis = new JPanel(new GridLayout(0, 4, 5, 5));
        for(String nome : Util.emojis){
            URL url = getClass().getResource("/images/emojis/" + nome + ".png");
            if(url != null){
                Image img = new ImageIcon(url).getImage().getScaledInstance(32, 32, Image.SCALE_SMOOTH);
                pnlEmojis.add(criarBotaoPopup(new ImageIcon(img), nome, "[emoji:" + nome + "]"));
            }
        }
        JPanel pnlGifs = new JPanel(new GridLayout(0, 2, 5, 5));
        for(String nome : Util.gifs){
            URL url = getClass().getResource("/images/gifs/" + nome + ".gif");
            if(url != null){
                pnlGifs.add(criarBotaoPopup(new ImageIcon(url), nome, "[gif:" + nome + "]"));
            }
        }
        abas.addTab("Emojis", pnlEmojis);
        abas.addTab("GIFs", pnlGifs);
        PopEmojis.add(abas);
    }

    private JButton criarBotaoPopup(ImageIcon icone, String nome, String token){
        JButton botao = new JButton(icone);
        botao.setToolTipText(nome);
        botao.setBorderPainted(false);
        botao.setContentAreaFilled(false);
        botao.addActionListener(e -> {
            TxtMensagem.replaceSelection(token);
            PopEmojis.setVisible(false);
            TxtMensagem.requestFocus();
        });
        return botao;
    }

    private void entrarModoManutencao(){
        if(emManutencao){
            return;
        }
        emManutencao = true;
        SwingUtilities.invokeLater(() -> {
            EdtConversa.setText("<center><h2><font color='red'>Servidor em manutenção</font></h2>"
                    + "Tentando reconectar...</center>");
            TxtMensagem.setEnabled(false);
            BtnEnviar.setEnabled(false);
            BtnEmoji.setEnabled(false);
        });
    }

    private void sairModoManutencao(){
        emManutencao = false;
        TxtMensagem.setEnabled(true);
        BtnEnviar.setEnabled(true);
        BtnEmoji.setEnabled(true);
    }

    private JPopupMenu PopEmojis;
    private volatile boolean emManutencao = false;
    private String ultimoHistorico = null;
    private static final java.util.logging.Logger logger = java.util.logging.Logger.getLogger(FrmChat.class.getName());
    public FrmChat() {
        initComponents();
        montarPopupEmojis();
        Thread.ofVirtual().start(()->{
            while (true){
                try{
                    Socket cliente = new Socket();
                    cliente.connect(new InetSocketAddress("200.128.142.91",Util.PortaEnvioDesktop), 2000);
                    ObjectInputStream input = new ObjectInputStream(cliente.getInputStream());
                    String msgs = input.readUTF();
                    input.close();
                    cliente.close();
                    // Só redesenha quando algo mudou, senão os GIFs reiniciam a cada segundo
                    if(emManutencao || !msgs.equals(ultimoHistorico)){
                        ultimoHistorico = msgs;
                        String html = renderizarTokens(msgs);
                        SwingUtilities.invokeLater(() -> {
                            try{
                                sairModoManutencao();
                                HTMLDocument doc = (HTMLDocument) EdtConversa.getDocument();
                                HTMLEditorKit kit = (HTMLEditorKit) EdtConversa.getEditorKit();
                                EdtConversa.setText("");
                                kit.insertHTML(doc,doc.getLength(),html,0,0,null); // 0,0,null = ponto inicial de inserção, niveis de tags a serem ignorados, tag para iniciar edição
                            } catch (Exception e){
                                JOptionPane.showMessageDialog(null,"Erro ao exibir mensagens:" + e.getMessage());
                                e.printStackTrace();
                            }
                        });
                    }
                } catch (IOException e){
                    // Servidor parado ou recusando conexão
                    entrarModoManutencao();
                } catch (Exception e){
                    JOptionPane.showMessageDialog(null,"Erro ao inicar Thread FrmChat:" + e.getMessage());
                    e.printStackTrace();
                }
                try{
                    Thread.sleep(1000);
                } catch (InterruptedException e){
                    return;
                }
            }
        });
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ScrConversa = new javax.swing.JScrollPane();
        EdtConversa = new javax.swing.JEditorPane();
        LblMensagem = new javax.swing.JLabel();
        TxtMensagem = new javax.swing.JTextField();
        LblModo = new javax.swing.JLabel();
        CBModo = new javax.swing.JComboBox<>();
        BtnEmoji = new javax.swing.JButton();
        BtnEnviar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Chat");

        EdtConversa.setEditable(false);
        EdtConversa.setContentType("text/html"); // NOI18N
        ScrConversa.setViewportView(EdtConversa);

        LblMensagem.setFont(new java.awt.Font("Liberation Sans", 1, 18)); // NOI18N
        LblMensagem.setText("Mensagem");

        TxtMensagem.setToolTipText("");
        TxtMensagem.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                TxtMensagemKeyPressed(evt);
            }
        });

        LblModo.setFont(new java.awt.Font("Liberation Sans", 1, 18)); // NOI18N
        LblModo.setText("Modo:");

        CBModo.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Fala", "Grita", "Xinga" }));

        BtnEmoji.setFont(new java.awt.Font("Liberation Sans", 1, 18)); // NOI18N
        BtnEmoji.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/emojis/Coracao.png"))); // NOI18N
        BtnEmoji.setText("Emojis / GIFs");
        BtnEmoji.addActionListener(this::BtnEmojiActionPerformed);

        BtnEnviar.setFont(new java.awt.Font("Liberation Sans", 1, 18)); // NOI18N
        BtnEnviar.setText("ENVIAR");
        BtnEnviar.addActionListener(this::BtnEnviarActionPerformed);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(ScrConversa)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(LblModo)
                            .addComponent(LblMensagem))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(TxtMensagem)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(CBModo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(BtnEmoji, javax.swing.GroupLayout.PREFERRED_SIZE, 175, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(BtnEnviar, javax.swing.GroupLayout.PREFERRED_SIZE, 175, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(0, 351, Short.MAX_VALUE)))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(ScrConversa, javax.swing.GroupLayout.PREFERRED_SIZE, 320, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(LblMensagem)
                    .addComponent(TxtMensagem, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(LblModo)
                    .addComponent(CBModo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(BtnEmoji, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(BtnEnviar, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(19, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void BtnEnviarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnEnviarActionPerformed
        this.gerarEenviarMensagem();
    }//GEN-LAST:event_BtnEnviarActionPerformed

    private void BtnEmojiActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BtnEmojiActionPerformed
        // Abre o popup logo acima do botão
        PopEmojis.show(BtnEmoji, 0, -PopEmojis.getPreferredSize().height);
    }//GEN-LAST:event_BtnEmojiActionPerformed

    private void TxtMensagemKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_TxtMensagemKeyPressed
        if(evt.getKeyCode() == KeyEvent.VK_ENTER){
            this.gerarEenviarMensagem();
        }
    }//GEN-LAST:event_TxtMensagemKeyPressed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ReflectiveOperationException | javax.swing.UnsupportedLookAndFeelException ex) {
            logger.log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> new FrmChat().setVisible(true));
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton BtnEmoji;
    private javax.swing.JButton BtnEnviar;
    private javax.swing.JComboBox<String> CBModo;
    private javax.swing.JEditorPane EdtConversa;
    private javax.swing.JLabel LblMensagem;
    private javax.swing.JLabel LblModo;
    private javax.swing.JScrollPane ScrConversa;
    private javax.swing.JTextField TxtMensagem;
    // End of variables declaration//GEN-END:variables
}
