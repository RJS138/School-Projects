package studentviewerfixme;

public class StudentCntl {

    private final StudentList studentList;
    private final StudentUI studentUI;

    public StudentCntl() {
        studentList = new StudentList();
        studentUI = new StudentUI(this);
    }

    void showGUI() {
        studentUI.setVisible(true);
    }

    String showFirstStudent() {
        return studentList.getFirstStudent().toString();
    }

    String getNextStudent() {
        return studentList.getNextStudent().toString();
    }

}
