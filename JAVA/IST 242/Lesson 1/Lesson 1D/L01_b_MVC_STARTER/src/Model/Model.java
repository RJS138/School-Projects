package Model;

import java.util.ArrayList;

public class Model
{
   private ArrayList <Person> people = new ArrayList <Person> ();

    public Model()
    {
        loadData();
    }

    public void loadData()
    {
        Height h1 = new Height (5, 2);
        Height h2 = new Height (5, 9);
        Height h3 = new Height (6, 1);
        Height h4 = new Height (6, 0);
        Person p1 = new Person("Marcus Allen", 200, "Upper Marlboro, Md.", "Dr. Henry A. Wise, Jr.", h1);
        Person p2 = new Person("Kyle Alston", 180, "Robbinsville, N.J.", "Robbinsville", h2);
        Person p3 = new Person("Troy Apke", 220, "Mt. Lebanon, Pa.", "Mount Lebanon", h3);
        Person p4 = new Person("Matthew Baney", 225, "State College, Pa.", "State College", h4);
        Person p5 = new Person(); 
        people.add(p1);
        people.add(p2);
        people.add(p3);
        people.add(p4);
        people.add(p5);
    }
    public String getData(int n)
    {
        return people.get(n).toString();
    }
    
    public ArrayList <String> getData ()
    {
        ArrayList <String> peopleList = new ArrayList<String>();
        for (Person person : people)
        {
            peopleList.add(person.toString());
        }
        return peopleList;
    }
}
