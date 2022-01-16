package View;

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
        for (String s : arr)
        {
            System.out.print(s + " ");
        }
        System.out.println("");
    }
    public void linesDisplay (ArrayList<ArrayList<String>> arrOfarr){
       for (ArrayList<String> i: arrOfarr)
       {
          System.out.println(i);
       }
    }

}
