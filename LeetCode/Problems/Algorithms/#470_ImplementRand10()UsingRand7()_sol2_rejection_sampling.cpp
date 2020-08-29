// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // A perfect uniform distribution using rejection sampling:
        // 1.) Generate a uniform random number in the range [0, 48],
        //     using the rand7() method of course;
        // 2.) Find the corresponding group/bucket of the generated number:
        //       Group 1: [0, 9] => contains 10 consecutive numbers;
        //       Group 2: [10, 19] => contains 10 consecutive numbers;
        //       Group 3: [20, 29] => contains 10 consecutive numbers;
        //       Group 4: [30, 39] => contains 10 consecutive numbers;
        //       Group 5: [40, 48] => contains only 9 consecutive numbers;
        //     Observations:
        //       -> the last digits of 10 consecutive numbers contains all the digits from 0 to 9 (exactly once).
        //       -> this condition is satisfied only by the first 4 groups.
        // 3.) If the generated number is in one of the first 4 groups
        //     then print 1 + the last digit of the generated number and stop
        //     else go to Step 1.) and start another experiment
        
        int num = 48;
        int group = 5;
        while(group == 5){
            num = (rand7() - 1) * 7 + (rand7() - 1);
            group = 1 + num / 10;
        }
        
        return 1 + (num % 10);
    }
};