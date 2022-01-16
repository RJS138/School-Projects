package Model;

public class Model
{
    Person p1;
    Person p2;
    Person p3;
    Person p4;
    Person p5;
    Height h1;
    Height h2;
    Height h3;
    Height h4;

    public Model()
    {
        loadData();
    }

    public void loadData()
    {
        h1 = new Height (5, 2);
        h2 = new Height (5, 9);
        h3 = new Height (6, 1);
        h4 = new Height (6, 0);
        p1 = new Person("Marcus Allen", 200, "Upper Marlboro, Md.", "Dr. Henry A. Wise, Jr.", h1);
        p2 = new Person("Kyle Alston", 180, "Robbinsville, N.J.", "Robbinsville", h2);
        p3 = new Person("Troy Apke", 220, "Mt. Lebanon, Pa.", "Mount Lebanon", h3);
        p4 = new Person("Matthew Baney", 225, "State College, Pa.", "State College", h4);
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
