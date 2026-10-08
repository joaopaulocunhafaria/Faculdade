import javax.swing.*;
import java.awt.*;

public class MainWindow extends JFrame {

  private CustomPanel1 panel1;
  private CustomRadioButton1 radioButton2;
  private CustomRadioButton2 radioButton3;
  private CustomRadioButton3 radioButton4;
  private CustomRadioButton4 radioButton5;
  private CustomButton1 button6;
  private CustomLabel1 label7;

  public MainWindow() {
    setTitle("MainWindow");
    setSize(1024, 768);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLayout(null);

    panel1 = new CustomPanel1();
    panel1.setBounds(93, 37, 461, 314);
    panel1.setLayout(null);
    this.add(panel1);

    radioButton2 = new CustomRadioButton1();
    radioButton2.setBounds(307, 123, 120, 28);
    radioButton2.setSelected(false);
    panel1.add(radioButton2);

    radioButton3 = new CustomRadioButton2();
    radioButton3.setBounds(300, 181, 120, 28);
    radioButton3.setSelected(false);
    panel1.add(radioButton3);

    radioButton4 = new CustomRadioButton3();
    radioButton4.setBounds(306, 68, 120, 28);
    radioButton4.setSelected(false);
    panel1.add(radioButton4);

    radioButton5 = new CustomRadioButton4();
    radioButton5.setBounds(171, 488, 120, 28);
    radioButton5.setSelected(false);
    this.add(radioButton5);

    button6 = new CustomButton1();
    button6.setBounds(136, 244, 120, 36);
    panel1.add(button6);

    label7 = new CustomLabel1();
    label7.setBounds(34, 83, 120, 28);
    panel1.add(label7);

    setLocationRelativeTo(null);
  }
  public static void main(String[] args) {
    SwingUtilities.invokeLater(() -> {
      MainWindow frame = new MainWindow();
      frame.setVisible(true);
    });
  }
}
