package Controller;

import Model.Model;
import View.View;

public class Controller
{
    Model model;
    View view;

    public Controller(View v, Model m)
    {
        model = m;
        view = v;

       v.basicDisplay(m.getData(1));
       v.basicDisplay(m.getData(2));
       v.basicDisplay(m.getData(3));
       v.basicDisplay(m.getData(4));
       v.basicDisplay(m.getData(5));
       v.basicDisplay(m.getData(6));
        
        
    }

}
