package investmentviewermvcfixme;

/**
 * Based on program in Big Java: Late Objects by Cay Horstmann
 */
public class InvestmentCntl {

    private final InvestmentModel model;
    private final InvestmentView view;

    public InvestmentCntl() {
        model = new InvestmentModel();
        view = new InvestmentView(this);
    }
    
    public double fetchStartingBalance() {
        return model.getINITIAL_BALANCE();
    }

    public double fetchStartingInterestRate() {
        return model.getINITIAL_RATE();
    }
    
    public double calcNewBalance(double interestRate) {
        return model.updateBalance(interestRate);
    }
    
    public InvestmentView getView() {
        return view;
    }

}
