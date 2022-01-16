package View;

import Model.Model;
import Model.Person;
import java.util.ArrayList;

public class View
{

    public View()
    {

    }
    public void basicDisplay(String s)
    {
    System.out.println(s);
    }
    public void basicDisplay(ArrayList<String> arr)
    {
        arr.forEach(System.out::println);
    }

}
