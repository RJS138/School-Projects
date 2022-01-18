package Controller;

import Model.Model;
import Model.Sort;
import View.FootballPlayerUI;
import View.View;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller implements  ActionListener
{

    Model model;
    View view;
    FootballPlayerUI footballPlayerUI;
    Sort sort;
    public Controller(View v, Model m)
    {
        model = m;
        view = v;
        footballPlayerUI = new FootballPlayerUI(model.getFpData().getTable(), 0);
        this.addButtons();
        sort = new Sort(model.getFpData().getTable());
        footballPlayerUI.setVisible(true);
// no changes needed in Controller
//The code below will work as it is if FootballPlayerData is implemented correctly
//
//=========used in L03B =====================================================
//        view.basicDisplay("------------------------------------------------------");
//        view.basicDisplay(model.getFpData().getHeaders());
//        view.basicDisplay("size of headers=" + model.getFpData().getHeaders().size());
//        view.basicDisplay("------------------------------------------------------");
//        view.basicDisplay(model.getFpData().getLine(100));
//        view.basicDisplay("------------------------------------------------------");
//        view.linesDisplay(model.getFpData().getLines(100, 103));
//        view.basicDisplay("size of lines=" + model.getFpData().getLines(100, 103).size());
//        view.basicDisplay("size of line 0=" + model.getFpData().getLines(100, 103).get(0).size());
//        view.basicDisplay("------------------------------------------------------");

//=========used in L03A =====================================================
//        view.basicDisplay(model.getMembers().get(1).getAttributeName(3));
//        view.basicDisplay(model.getMembers().get(1).getAttribute(3));
//        view.basicDisplay(model.getMembers().get(1).getAttributeNames());
//        view.basicDisplay(model.getMembers().get(1).getAttributes());
//        view.basicDisplay("size of names=" + model.getMembers().get(1).getAttributeNames().size());
//        view.basicDisplay("size of attributes=" + model.getMembers().get(1).getAttributes().size());
    }
    public void addButtons() {
        footballPlayerUI.previousBtn.addActionListener(this);
        footballPlayerUI.nextBtn.addActionListener(this);
        footballPlayerUI.updateBtn.addActionListener(this);
        footballPlayerUI.addnewBtn.addActionListener(this);
        footballPlayerUI.deleteBtn.addActionListener(this);
        footballPlayerUI.exitBtn.addActionListener(this);
        footballPlayerUI.sortNameBtn.addActionListener(this);
        footballPlayerUI.sortHeightBtn.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object action = e.getSource();
        if (action == footballPlayerUI.nextBtn) {
            if (footballPlayerUI.getCurrentPlayer() == footballPlayerUI.getList().size() - 1) {
                System.out.println("You are on the last Player in the List.");
            }
            else {
                footballPlayerUI.setCurrentPlayer(footballPlayerUI.getCurrentPlayer() + 1);
                footballPlayerUI.refresh();
            }
        }
        if (action == footballPlayerUI.previousBtn) {
            if (footballPlayerUI.getCurrentPlayer() == 0) {
                System.out.println("You are on the first Player in the List.");
            }
            else {
                footballPlayerUI.setCurrentPlayer(footballPlayerUI.getCurrentPlayer() - 1);
                footballPlayerUI.refresh();
            }
        }
        if (action == footballPlayerUI.exitBtn) {
            System.exit(0);
        }
        if (action == footballPlayerUI.sortNameBtn) {
            sort.sortByName();
            footballPlayerUI.setList(sort.getList());
            footballPlayerUI.setCurrentPlayer(0);
            footballPlayerUI.refresh();
            view.linesDisplay(model.getFpData().getLines(0,10));
        }
        if (action == footballPlayerUI.sortHeightBtn) {
            sort.sortByHeight();
            footballPlayerUI.setList(sort.getList());
            footballPlayerUI.setCurrentPlayer(0);
            footballPlayerUI.refresh();
            view.linesDisplay(model.getFpData().getLines(0,10));
        }
    }
}
