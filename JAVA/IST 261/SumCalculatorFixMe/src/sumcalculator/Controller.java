package sumcalculator;

public class Controller {

    private final Model model;
    private final View view;
    
    public Controller() {
        model = new Model();
        view = new View(this);
    }
     
    public View getView() {
        return view;
    }
    
    public boolean isValid(String userNums) {
        return model.isValid(userNums);
       
    }
    public String errorMsg(String input) {
        return model.errorMsg(input);
    }
    
    public int computeSum(String nums) {
        return model.computeSum(nums);
    }
    


}
