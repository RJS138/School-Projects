package sumcalculator;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public final class View extends JFrame {

    private static final int FRAME_WIDTH = 700;
    private static final int FRAME_HEIGHT = 300;

    private static final int AREA_ROWS = 10;
    private static final int AREA_COLUMNS = 30;

    static final String INPUT_SPECIFIER = "\nEnter six different "
            + "integers from 1 through 60, separated by spaces";
    static final String INPUT_LABEL = "\n Enter the ammount of " 
            + "simulations to run from 1 to 10.";
    
    private JLabel label;
    private JLabel label2;
    private JTextField textField;
    private JTextField textField2;
    private JButton button;
    private final JTextArea resultArea;

    private final Controller cntl;

    public View(Controller controller) {
        super("Deliverable 2: Lottery");
        cntl = controller;
        resultArea = new JTextArea(AREA_ROWS, AREA_COLUMNS);
        resultArea.setEditable(false);
        resultArea.setText("");

        createTextField();
        createTextField2();
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
    
    private void createTextField2() {
        label2= new JLabel(INPUT_LABEL);
        final int FIELD_WIDTH = 5;
        textField2= new JTextField(FIELD_WIDTH);
    }

    private void createButton() {
        button = new JButton("Run Simulation");
        // for this sytle of lambda expression, see video from our libraries at
        // https://learning.oreilly.com/videos/core-java/9780134540603/9780134540603-CORJ_06_05/
        // from minute 2:00 to minute 4:00
        button.addActionListener(event -> showSum(textField.getText()));
    }

    private void createPanel() {
        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(textField);
        panel.add(label2);
        panel.add(textField2);
        JScrollPane scrollPane = new JScrollPane(resultArea);
        panel.add(scrollPane);
        panel.add(button);
        add(panel);
    }

    public void displaySelf() {
        this.setVisible(true);
    }

    private void showSum(String input) {
        if (cntl.isValid(input) && cntl.isDuration(textField2.getText())) {
            resultArea.setText("");
            resultArea.append(cntl.runLottery(input, textField2.getText()) + "\n");
        } else {
            javax.swing.JOptionPane.showMessageDialog(new javax.swing.JFrame(),
                    cntl.errorMsg(input));
            // http://www.java2s.com/Tutorial/Java/0240__Swing/SetthefocusonaparticularJTextField.htm
            textField.requestFocus();
        }
    }

}
