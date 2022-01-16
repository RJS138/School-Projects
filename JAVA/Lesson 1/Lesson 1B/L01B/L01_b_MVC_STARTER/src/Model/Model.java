package Model;

public class Model
{
    Person p1;
    Person p2;
    Person p3;
    Person p4;
    Person p5;

    public Model()
    {
        loadData();
    }

    public void loadData()
    {
        p1 = new Person("Marcus Allen", 200, "Upper Marlboro, Md.", "Dr. Henry A. Wise, Jr.");
        p2 = new Person("Kyle Alston", 180, "Robbinsville, N.J.", "Robbinsville");
        p3 = new Person("Troy Apke", 220, "Mt. Lebanon, Pa.", "Mount Lebanon");
        p4 = new Person("Matthew Baney", 225, "State College, Pa.", "State College");
        p5 = new Person(); 
    }
    public String getData(int n)
    {
        switch (n)
        {
            case 1:
                return p1.toString();
            case 2:
                return p2.toString();
            case 3:
                return p3.toString(); 
            case 4:
                return p4.toString();
            case 5:
                return p5.toString();
            default:
                return "invalid input parameter";
           
                
        }
    }
}
