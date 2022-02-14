package sumcalculator;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Random;

public class Model {

    private final List<Integer> userInput;
    private final List<Integer> lotteryNums;
    private List<Integer> matchingNums;
    private final Random rand = new Random();
    private final StringBuilder outputString;

    private static final String INPUT_PARSE_ERROR = "Input is not six integers "
            + "separated by spaces\n";
    private static final String DUPLICATE_VALUES_ERROR = "Input contains "
            + "repeated values";
    private static final String OUT_OF_BOUNDS_ERROR = "Input contains a value "
            + "that is not an integer from 1 through 60";

    public Model() {
        userInput = new ArrayList<>();
        lotteryNums = new ArrayList<>();
        outputString = new StringBuilder();
        matchingNums = new ArrayList<>();
    }

    public String runLottery(String numbers) {
        //This clears previosu inputs when doing multiple attempts in one instance
        userInput.clear();
        lotteryNums.clear();
        matchingNums.clear();
        //NetBeans states to check my REGEX but I found it works after testing. 
        String[] input = numbers.split("\\s+");
        for (String input1 : input) {
            userInput.add(Integer.parseInt(input1));
        }
        for (int i = 0; i < 6; i++) {
            lotteryNums.add(1 + (rand.nextInt(60)));
        }

        matchingNums = getMatchingNums(userInput, lotteryNums);

        outputString.append("User Input Is: \n");
        outputString.append(userInput);
        outputString.append("\nLottery Draw Is: \n");
        outputString.append(lotteryNums);
        outputString.append("\nYour Matching Numbers Are: \n");
        outputString.append(matchingNums);
        return outputString.toString();

    }

    public boolean isValid(String nums) {
        //NetBeans states to check my REGEX but I found it works after testing. 
        String[] input = nums.split("\\s+");
        for (int i = 0; i < input.length; i++) {
            if (input.length == 6) {
                //NetBeans states to check my REGEX but I found it works after testing. 
                if (input[i].matches("\\d{1,2}")) {
                    if (1 <= Integer.parseInt(input[i]) && Integer.parseInt(input[i]) <= 60) {
                        if (isDuplicate(nums)) {
                            System.out.println("Pass" + i);
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }

        }
        return true;
    }

    public String errorMsg(String nums) {
        //NetBeans states to check my REGEX but I found it works after testing. 
        String[] input = nums.split("\\s+");
        for (int i = 0; i < input.length; i++) {
            if (input.length == 6) {
                //NetBeans states to check my REGEX but I found it works after testing. 
                if (input[i].matches("\\d{1,2}")) {
                    if (1 <= Integer.parseInt(input[i]) && Integer.parseInt(input[i]) <= 60) {
                        if (isDuplicate(nums)) {
                            System.out.println("Pass" + i);
                        } else {
                            return DUPLICATE_VALUES_ERROR;
                        }
                    } else {
                        return OUT_OF_BOUNDS_ERROR;
                    }
                } else {
                    return INPUT_PARSE_ERROR;
                }
            } else {
                return INPUT_PARSE_ERROR;
            }

        }
        return INPUT_PARSE_ERROR;
    }

    private boolean isDuplicate(String nums) {
        //NetBeans states to check my REGEX but I found it works after testing.
        String[] input = nums.split("\\s+");
        for (int a = 0; a < input.length; a++) {
            for (int b = a + 1; b < input.length; b++) {
                if (Integer.parseInt(input[a]) == Integer.parseInt(input[b])) {
                    return false;
                }
            }
        }
        return true;
    }

    private List<Integer> getMatchingNums(List<Integer> userInput, List<Integer> lotteryNums) {
        for (int a = 0; a < userInput.size(); a++) {
            for (int b = a + 1; b < userInput.size(); b++) {
                if (Objects.equals(userInput.get(a), lotteryNums.get(b))) {
                    matchingNums.add(userInput.get(a));
                }
            }
        }
        return matchingNums;
    }
}
