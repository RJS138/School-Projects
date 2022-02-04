package studentviewerfixme;

import java.util.ArrayList;
import java.util.List;

public class StudentList {

    private final static int STARTING_INDEX = 0;
    private final List<Student> students;
    private int currentIndex;

    public StudentList() {
        students = new ArrayList<>();
        addInitialStudentsToList();
    }

    private void addInitialStudentsToList() {
        students.add(new Student("John", "Doe", "3.1"));
        students.add(new Student("Jane", "Deere", "3.25"));
        students.add(new Student("Sam", "Spade", "2.9"));
    }

    Student getNextStudent() {
        if (currentIndex == students.size() - 1) {
            currentIndex = STARTING_INDEX;
        } else {
            currentIndex++;
        }
        return students.get(currentIndex);
    }

    Student getFirstStudent() {
        return students.get(STARTING_INDEX);

    }

}
