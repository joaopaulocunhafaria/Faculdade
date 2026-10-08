import javax.swing.*;
import java.awt.Color;
import helper_classes.*;

public class WindowBuilder {
  public static void main(String[] args) {

     JFrame frame = new JFrame("My Awesome Window");
     frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     frame.setSize(1238, 669);
     JPanel panel = new JPanel();
     panel.setLayout(null);
     panel.setBackground(Color.decode("#1e1e1e"));

     JLabel element2 = new JLabel("Painel de Controle");
     element2.setBounds(345, 61, 450, 50);
     element2.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 50));
     element2.setForeground(Color.decode("#D9D9D9"));
     panel.add(element2);

     JButton element3 = new JButton("Ativar ");
     element3.setBounds(673, 250, 106, 29);
     element3.setBackground(Color.decode("#2e2e2e"));
     element3.setForeground(Color.decode("#D9D9D9"));
     element3.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 14));
     element3.setBorder(new RoundedBorder(4, Color.decode("#979797"), 1));
     element3.setFocusPainted(false);
     OnClickEventHelper.setOnClickColor(element3, Color.decode("#232323"), Color.decode("#2e2e2e"));
     panel.add(element3);

     JButton element4 = new JButton("Ativar");
     element4.setBounds(675, 361, 106, 29);
     element4.setBackground(Color.decode("#2e2e2e"));
     element4.setForeground(Color.decode("#D9D9D9"));
     element4.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 14));
     element4.setBorder(new RoundedBorder(4, Color.decode("#979797"), 1));
     element4.setFocusPainted(false);
     OnClickEventHelper.setOnClickColor(element4, Color.decode("#232323"), Color.decode("#2e2e2e"));
     panel.add(element4);

     JButton element5 = new JButton("Ativar");
     element5.setBounds(676, 468, 106, 29);
     element5.setBackground(Color.decode("#2e2e2e"));
     element5.setForeground(Color.decode("#D9D9D9"));
     element5.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 14));
     element5.setBorder(new RoundedBorder(4, Color.decode("#979797"), 1));
     element5.setFocusPainted(false);
     OnClickEventHelper.setOnClickColor(element5, Color.decode("#232323"), Color.decode("#2e2e2e"));
     panel.add(element5);

     JLabel element6 = new JLabel("Serviço Desktop");
     element6.setBounds(167, 241, 300, 40);
     element6.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 30));
     element6.setForeground(Color.decode("#D9D9D9"));
     panel.add(element6);

     JLabel element7 = new JLabel("Serviço Web");
     element7.setBounds(170, 351, 300, 40);
     element7.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 30));
     element7.setForeground(Color.decode("#D9D9D9"));
     panel.add(element7);

     JLabel element8 = new JLabel("Serviços Terceiros");
     element8.setBounds(165, 458, 300, 40);
     element8.setFont(CustomFontLoader.loadFont("./resources/fonts/Lato.ttf", 30));
     element8.setForeground(Color.decode("#D9D9D9"));
     panel.add(element8);

     frame.add(panel);
     frame.setVisible(true);

  }
}