package sumcalculator;

public class Model {

    private int sum;

    private static final String INPUT_PARSE_ERROR = "Input is not six integers "
            + "separated by spaces\n";
    private static final String DUPLICATE_VALUES_ERROR = "Input contains "
            + "repeated values";
    private static final String OUT_OF_BOUNDS_ERROR = "Input contains a value "
            + "that is not an integer from 1 through 60";

    public Model() {
        sum = 0;
    }

    public int computeSum(String numbers) {
        sum = 0;
        //NetBeans states to check my REGEX but I found it works after testing. 
        String[] input = numbers.split("\\s+");
        for (String input1 : input) {
            sum += Integer.parseInt(input1);
        }
        return sum;
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
}
