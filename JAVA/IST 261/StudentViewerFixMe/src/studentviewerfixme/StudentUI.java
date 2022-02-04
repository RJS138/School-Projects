package studentviewerfixme;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class StudentUI extends JFrame {

    private static final int FRAME_WIDTH = 600;
    private static final int FRAME_HEIGHT = 350;

    private static final int AREA_ROWS = 10;
    private static final int AREA_COLUMNS = 30;

    private JButton buttonCycleThrough;
    private JTextArea resultArea;
    private final StudentCntl cntl;

    public StudentUI(StudentCntl studentCntl) {
        super("Student Viewer");
        this.cntl = studentCntl;
        initComponents();
    }

    private void initComponents() {

        resultArea = new JTextArea(AREA_ROWS, AREA_COLUMNS);
        resultArea.setEditable(false);
        showFirstStudent();

        // create button and add its action listener, lambda style
        buttonCycleThrough = new JButton("Cycle through students");
        buttonCycleThrough.addActionListener(event -> cycleThroughStudents());

        // Hitting Enter "clicks" button - https://stackoverflow.com/questions/13731710
        getRootPane().setDefaultButton(buttonCycleThrough); // 

        // create Panel and add components to it
        JPanel panel = new JPanel();
        panel.add(buttonCycleThrough);
        JScrollPane scrollPane = new JScrollPane(resultArea);
        panel.add(scrollPane);
        add(panel);

        setSize(FRAME_WIDTH, FRAME_HEIGHT);
        setLocationRelativeTo(null); // centers frame
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void showFirstStudent() {
        resultArea.setText(cntl.showFirstStudent());
        resultArea.append("");
    }

    private void cycleThroughStudents() {
        resultArea.setText(cntl.getNextStudent());
        resultArea.append("");
    }

}
