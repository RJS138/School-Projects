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
    private String errorMsg;
    private int runsLeft;
    private int currentRun;

    private static final String INPUT_PARSE_ERROR = "Input is not six integers "
            + "separated by spaces\n";
    private static final String DUPLICATE_VALUES_ERROR = "Input contains "
            + "repeated values";
    private static final String OUT_OF_BOUNDS_ERROR = "Input contains a value "
            + "that is not an integer from 1 through 60";
    private static final String RUNS_OOB_ERROR = "Runs contains a value that is"
            + " not an integer from 1 to 10";
    private static final String RUNS_PARSE_ERROR = "Runs is not one valid "
            + "integer";

    public Model() {
        userInput = new ArrayList<>();
        lotteryNums = new ArrayList<>();
        outputString = new StringBuilder();
        matchingNums = new ArrayList<>();
    }

    public String runLottery(String numbers, String runs) {
        //This clears previosu inputs when doing multiple attempts in one instance
        userInput.clear();
        lotteryNums.clear();
        matchingNums.clear();
        currentRun = 1;

        String[] input = numbers.split("\\s+");
        for (String input1 : input) {
            userInput.add(Integer.parseInt(input1));
        }
        runsLeft = Integer.parseInt(runs);
        outputString.append("\nThe numbers you chose are: ");
        outputString.append(userInput);
        outputString.append("\n");

        while (runsLeft != 0) {
            for (int i = 0; i < 6; i++) {
                int nextInt = rand.nextInt(60);
                if (isDuplicateNums(lotteryNums, nextInt)) {
                    if (nextInt == 0) {
                        if (isDuplicateNums(lotteryNums, (nextInt + 1))) {
                            lotteryNums.add(nextInt + 1);
                        } else {
                            i--;
                        }
                    }
                    lotteryNums.add(nextInt);
                } else {
                    i--;
                }

            }
            matchingNums = getMatchingNums(userInput, lotteryNums);
            outputString.append("\nFor Drawing ").append(currentRun).append(", the lotto numbers are ").append(lotteryNums).append(", which match these numbers you entered: ").append(matchingNums).append(".");
            lotteryNums.clear();
            matchingNums.clear();
            runsLeft--;
            currentRun++;
        }

        return outputString.toString();

    }

    public boolean isValid(String nums) {
        //NetBeans states to check my REGEX but I found it works after testing. 
        String[] input = nums.split("\\s+");
        for (int i = 0; i < input.length; i++) {
            if (input.length == 6) {
                if (input[i].matches("\\d{1,2}")) {
                    if (1 <= Integer.parseInt(input[i]) && Integer.parseInt(input[i]) <= 60) {
                        if (isDuplicate(nums)) {
                            System.out.println("Pass" + i);
                        } else {
                            errorMsg = DUPLICATE_VALUES_ERROR;
                            return false;
                        }
                    } else {
                        errorMsg = OUT_OF_BOUNDS_ERROR;
                        return false;
                    }
                } else {
                    errorMsg = INPUT_PARSE_ERROR;
                    return false;
                }
            } else {
                errorMsg = INPUT_PARSE_ERROR;
                return false;
            }
        }
        errorMsg = INPUT_PARSE_ERROR;
        return true;
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

    private boolean isDuplicateNums(List<Integer> nums, Integer num) {
        for (int i = 0; i < nums.size(); i++) {
            if (Objects.equals(nums.get(i), num)) {
                return false;
            }
        }
        return true;
    }

    private List<Integer> getMatchingNums(List<Integer> userInput, List<Integer> lotteryNums) {
        for (int a = 0; a < userInput.size(); a++) {
            for (int b = 0; b < userInput.size(); b++) {
                if (Objects.equals(userInput.get(a), lotteryNums.get(b))) {
                    matchingNums.add(userInput.get(a));
                }
            }
        }
        return matchingNums;
    }

    boolean isRunsValid(String nums) {
        String[] input = nums.split("\\s+");
        for (int i = 0; i < input.length; i++) {
            if (input.length == 1) {
                if (input[i].matches("\\d{1,2}")) {
                    if (1 <= Integer.parseInt(input[i]) && Integer.parseInt(input[i]) <= 10) {
                        if (isDuplicate(nums)) {
                            System.out.println("Pass" + i);
                        } else {
                            errorMsg = DUPLICATE_VALUES_ERROR;
                            return false;
                        }
                    } else {
                        errorMsg = RUNS_OOB_ERROR;
                        return false;
                    }
                } else {
                    errorMsg = RUNS_PARSE_ERROR;
                    return false;
                }
            } else {
                errorMsg = RUNS_PARSE_ERROR;
                return false;
            }
        }
        errorMsg = RUNS_PARSE_ERROR;
        return true;
    }

    String geteErrorMsg(String input) {
        return errorMsg;
    }
}
