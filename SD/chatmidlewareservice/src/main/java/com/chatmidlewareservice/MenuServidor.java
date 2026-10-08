package com.chatmidlewareservice;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import java.awt.*;

public class MenuServidor {
    SystemTray tray;
    TrayIcon icon;
    PopupMenu popup; 
    MenuItem menuPainelControle, menuItWeb, menuItDesktop, menuItTerceiros, menuItPublicidade;
    Menu menuAcoes;


    public MenuServidor() {
        try {
            // CORREÇÃO: Adicionada a exclamação (!) para testar se NÃO é suportado
            if (!SystemTray.isSupported()) {
                System.out.println("Sem suporte para o SystemTray neste sistema!");
                JOptionPane.showMessageDialog(null, "SystemTray não é suportado neste ambiente.");
                return;
            }

            // Se passar pelo IF, significa que É suportado. O código continua aqui:
            tray = SystemTray.getSystemTray();

            // Dica: Certifique-se de que a imagem existe neste caminho relativo
            ImageIcon imgIcon = new ImageIcon("images/images.png", "Servidor Chat");
            icon = new TrayIcon(imgIcon.getImage());
            icon.setImageAutoSize(true);

            popup = new PopupMenu();
            menuPainelControle = new MenuItem("Abrir Painel de Controle");

            // Ajustado para CheckboxMenuItem para bater com a sua inicialização
            menuItWeb = new CheckboxMenuItem("Servidor Web");
            menuItDesktop = new CheckboxMenuItem("Servidor Desktop");
            menuItTerceiros = new CheckboxMenuItem("Servidor Terceiros");
            menuItPublicidade = new CheckboxMenuItem("Servidor Publicidade");

            menuAcoes = new Menu("Ações");

            popup.add(menuPainelControle);
            popup.addSeparator();

            menuAcoes.add(menuItDesktop);
            menuAcoes.add(menuItWeb);
            menuAcoes.add(menuItTerceiros);
            menuAcoes.addSeparator();
            menuAcoes.add(menuItPublicidade);

            popup.add(menuAcoes);
            icon.setPopupMenu(popup);

            tray.add(icon);

        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro ao criar menu do servidor de chat: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
}
