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

       v.basicDisplay(m.getData());
        
        
    }

}
