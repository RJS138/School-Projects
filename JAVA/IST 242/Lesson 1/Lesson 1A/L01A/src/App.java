
public class App {

    public static void main(String[] args) {
        //Creates the required ammount of students with info provided
        Person p1 = new Person("Marcus Allen", 200, "Upper Marlboro, Md.", "Dr. Henry A. Wise, Jr.");
        Person p2 = new Person("Kyle Alston", 180, "Robbinsville, N.J.", "Robbinsville");
        Person p3 = new Person("Troy Apke", 220, "Mt. Lebanon, Pa.", "Mount Lebanon");
        Person p4 = new Person("Matthew Baney", 225, "State College, Pa.", "State College");
        Person p5 = new Person();

        //Displays each created object above
        System.out.println(p1.toString());
        System.out.println(p2.toString());
        System.out.println(p3.toString());
        System.out.println(p4.toString());
        System.out.println(p5.toString());

    }
}
