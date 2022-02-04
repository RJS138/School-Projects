package investmentviewermvcfixme;

/**
 * Based on program in Big Java: Late Objects by Cay Horstmann
 */
public class InvestmentModel {

    private static final double INITIAL_RATE = 5;
    private static final double INITIAL_BALANCE = 1000;
    
    private double balance;
    
    public InvestmentModel() {
        this.balance = INITIAL_BALANCE;
    }
    
    public double updateBalance(double interestRate) {
        double interest = balance * interestRate /100;
        balance += interest;
        return balance;
    }

    public double getINITIAL_RATE() {
        return INITIAL_RATE;
    }

    public double getINITIAL_BALANCE() {
        return INITIAL_BALANCE;
    }

}
