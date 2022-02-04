package investmentviewermvcfixme;

/**
 * Based on program in Big Java: Late Objects by Cay Horstmann
 */
public class InvestmentApp {

    public static void main(String[] args) {
        //https://docs.oracle.com/javase/tutorial/uiswing/concurrency/initial.html
        javax.swing.SwingUtilities.invokeLater(() -> {
            InvestmentCntl cntl = new InvestmentCntl();
            cntl.getView().displaySelf();
        });
    }

}
