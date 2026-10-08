package com.urnadigital.eleitor;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingConstants;
import javax.swing.SwingWorker;
import java.awt.BorderLayout;
import java.awt.Font;

public class TelaVotacao extends JFrame {

    private static final String[] CANDIDATOS = { "Ana Souza", "Bruno Lima", "Carla Mendes" };

    private final ButtonGroup grupoVotos = new ButtonGroup();
    private final JRadioButton[] radioCandidatos = new JRadioButton[CANDIDATOS.length];
    private JRadioButton radioBranco;
    private JRadioButton radioNulo;
    private JButton botaoVotar;

    public TelaVotacao() {
        super("Urna Eletrônica");
        montarTela();
    }

    private void montarTela() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        JLabel titulo = new JLabel("Selecione o candidato", SwingConstants.CENTER);
        titulo.setFont(new Font("Arial", Font.BOLD, 22));
        titulo.setBorder(BorderFactory.createEmptyBorder(20, 10, 15, 10));
        add(titulo, BorderLayout.NORTH);

        JPanel painelOpcoes = new JPanel();
        painelOpcoes.setLayout(new BoxLayout(painelOpcoes, BoxLayout.Y_AXIS));
        painelOpcoes.setBorder(BorderFactory.createEmptyBorder(10, 40, 10, 40));

        for (int i = 0; i < CANDIDATOS.length; i++) {
            radioCandidatos[i] = new JRadioButton((i + 1) + " - " + CANDIDATOS[i]);
            radioCandidatos[i].setFont(new Font("Arial", Font.PLAIN, 16));
            grupoVotos.add(radioCandidatos[i]);
            painelOpcoes.add(radioCandidatos[i]);
            painelOpcoes.add(Box.createVerticalStrut(8));
        }

        radioBranco = new JRadioButton("Branco");
        radioBranco.setFont(new Font("Arial", Font.PLAIN, 16));
        grupoVotos.add(radioBranco);
        painelOpcoes.add(radioBranco);
        painelOpcoes.add(Box.createVerticalStrut(8));

        radioNulo = new JRadioButton("Nulo");
        radioNulo.setFont(new Font("Arial", Font.PLAIN, 16));
        grupoVotos.add(radioNulo);
        painelOpcoes.add(radioNulo);

        add(painelOpcoes, BorderLayout.CENTER);

        botaoVotar = new JButton("Votar e aguardar apuração");
        botaoVotar.setFont(new Font("Arial", Font.BOLD, 16));
        botaoVotar.addActionListener(e -> votar());

        JPanel painelBotao = new JPanel();
        painelBotao.setBorder(BorderFactory.createEmptyBorder(10, 10, 20, 10));
        painelBotao.add(botaoVotar);
        add(painelBotao, BorderLayout.SOUTH);

        setSize(440, 430);
        setLocationRelativeTo(null);
    }

    private void votar() {
        int voto = votoSelecionado();
        if (voto == 0) {
            JOptionPane.showMessageDialog(this, "Selecione uma opção antes de votar.", "Aviso",
                    JOptionPane.WARNING_MESSAGE);
            return;
        }

        botaoVotar.setEnabled(false);
        botaoVotar.setText("Aguardando apuração...");

        SwingWorker<String, Void> worker = new SwingWorker<>() {
            @Override
            protected String doInBackground() throws Exception {
                return new Eleitor().votar(voto);
            }

            @Override
            protected void done() {
                try {
                    String resultado = get();
                    new TelaResultado(resultado).setVisible(true);
                    dispose();
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(TelaVotacao.this,
                            "Erro ao votar: " + ex.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
                    botaoVotar.setEnabled(true);
                    botaoVotar.setText("Votar e aguardar apuração");
                }
            }
        };
        worker.execute();
    }

    private int votoSelecionado() {
        for (int i = 0; i < radioCandidatos.length; i++) {
            if (radioCandidatos[i].isSelected()) {
                return i + 1;
            }
        }
        if (radioBranco.isSelected()) {
            return Eleitor.VOTO_BRANCO;
        }
        if (radioNulo.isSelected()) {
            return Eleitor.VOTO_NULO;
        }
        return 0;
    }
}
