package com.urnadigital.eleitor;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import java.awt.BorderLayout;
import java.awt.Font;

public class TelaResultado extends JFrame {

    public TelaResultado(String resultado) {
        super("Resultado da Votação");
        montarTela(resultado);
    }

    private void montarTela(String resultado) {
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        JTextArea texto = new JTextArea(resultado);
        texto.setEditable(false);
        texto.setFont(new Font("Arial", Font.PLAIN, 16));
        texto.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        add(new JScrollPane(texto), BorderLayout.CENTER);

        JButton botaoFechar = new JButton("Fechar");
        botaoFechar.setFont(new Font("Arial", Font.BOLD, 14));
        botaoFechar.addActionListener(e -> System.exit(0));

        JPanel painelBotao = new JPanel();
        painelBotao.setBorder(BorderFactory.createEmptyBorder(0, 0, 15, 0));
        painelBotao.add(botaoFechar);
        add(painelBotao, BorderLayout.SOUTH);

        setSize(430, 320);
        setLocationRelativeTo(null);
    }
}
