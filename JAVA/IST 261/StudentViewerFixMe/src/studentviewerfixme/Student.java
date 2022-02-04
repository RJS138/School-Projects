package studentviewerfixme;

public final class Student {

    private final String firstName;
    private final String lastName;
    private final String gpa;

    public Student(String firstName, String lastName, String gpa) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        return "firstName: " + firstName + "\n"
                + "lastName: " + lastName + "\n"
                + "gpa: " + gpa + "\n";
    }

}
