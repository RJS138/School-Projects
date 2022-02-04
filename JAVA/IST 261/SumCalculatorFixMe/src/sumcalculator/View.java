package sumcalculator;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public final class View extends JFrame {

    private static final int FRAME_WIDTH = 800;
    private static final int FRAME_HEIGHT = 250;

    private static final int AREA_ROWS = 10;
    private static final int AREA_COLUMNS = 30;

    static final String INPUT_SPECIFIER = "\nEnter six different "
            + "integers from 1 through 60, separated by spaces";
    
    private JLabel label;
    private JTextField textField;
    private JButton button;
    private final JTextArea resultArea;

    private final Controller cntl;

    public View(Controller controller) {
        super("Sum Calculator");
        cntl = controller;
        resultArea = new JTextArea(AREA_ROWS, AREA_COLUMNS);
        resultArea.setEditable(false);
        resultArea.setText("");

        createTextField();
        createButton();
        createPanel();

        setSize(FRAME_WIDTH, FRAME_HEIGHT);
        setLocationRelativeTo(null); // centers frame
        setDefaultCloseOperation(EXIT_ON_CLOSE); // quits when frame closed
        //https://stackoverflow.com/questions/13731710/allowing-the-enter-key-to-press-the-submit-button-as-opposed-to-only-using-mo
        getRootPane().setDefaultButton(button);
    }

    private void createTextField() {
        label = new JLabel(INPUT_SPECIFIER);
        final int FIELD_WIDTH = 10;
        textField = new JTextField(FIELD_WIDTH);
    }

    private void createButton() {
        button = new JButton("Compute Sum");
        // for this sytle of lambda expression, see video from our libraries at
        // https://learning.oreilly.com/videos/core-java/9780134540603/9780134540603-CORJ_06_05/
        // from minute 2:00 to minute 4:00
        button.addActionListener(event -> showSum(textField.getText()));
    }

    private void createPanel() {
        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(textField);
        JScrollPane scrollPane = new JScrollPane(resultArea);
        panel.add(scrollPane);
        panel.add(button);
        add(panel);
    }

    public void displaySelf() {
        this.setVisible(true);
    }

    private void showSum(String input) {
        if (cntl.isValid(input)) {
            resultArea.setText("");
            resultArea.append(cntl.computeSum(input) + "\n");
        } else {
            javax.swing.JOptionPane.showMessageDialog(new javax.swing.JFrame(),
                    cntl.errorMsg(input));
            // http://www.java2s.com/Tutorial/Java/0240__Swing/SetthefocusonaparticularJTextField.htm
            textField.requestFocus();
        }
    }

}
