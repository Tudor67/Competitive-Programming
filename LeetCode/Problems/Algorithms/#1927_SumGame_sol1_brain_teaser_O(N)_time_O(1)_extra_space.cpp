class Solution {
public:
    bool sumGame(string num) {
        /*
           Case 0: Only digits (without '?')
                   If left sum == right sum => Bob wins;
                   otherwise => Alice wins;

           Case 1: Odd number of '?'
                   Let's look at the last turn of the game:
                   Case a.) (before the last turn) left sum == right sum;
                            (during the last turn) Alice takes the last turn and replaces the last '?'
                                                   with any digit greater than '0' to change one sum;
                            (after the last turn) left sum != right sum => Alice wins;
                   Case b.) (before the last turn) left sum != right sum;
                            (during the last turn) Alice takes the last turn and replaces the last '?'
                                                   with '0' to maintain both sums;
                            (after the last turn) left sum != right sum => Alice wins;
                   Alice always wins;
           
           Case 2: Even number of '?'
                   Question marks on opposite sides cancel each other:
                     * imagine that each player copies opponent's turn on the opposite side;
                   In this way we reduce the problem to a string containing '?' marks only on one side
                   (let's call it side S);
                     * examples: "??1 1??" -> "1 1", "?2?? 4?35" -> "?2? 435";
                   If Alice replaces one '?' to digit x, Bob can always replace one '?' to 9 - x;
                     * each pair of Alice - Bob (x, 9 - x) turns will increase the sum of side S by 9;
                     * in other words, "??" will increase the sum of side S by 9;
                     * this is the best strategy Bob can follow in order to win the game;
                       why? because he can only increase the sum to 9 (he cannot decrease the sum);
                   After replacing all "??" with 9: 
                     * if the sum of side S is equal to the sum of the opposite side => Bob wins;
                       otherwise => Alice wins;
        */
        const int N = num.length();
        
        int lDigitSum = 0;
        int lQCount = 0;
        int rDigitSum = 0;
        int rQCount = 0;
        
        for(int i = 0; i < N; ++i){
            if(isdigit(num[i])){
                if(i < N / 2){
                    lDigitSum += (num[i] - '0');
                }else{
                    rDigitSum += (num[i] - '0');
                }
            }else{
                if(i < N / 2){
                    ++lQCount;
                }else{
                    ++rQCount;
                }
            }
        }
        
        // Case 0: Only digits (without '?')
        if((lQCount + rQCount) == 0){
            return (lDigitSum != rDigitSum);
        }
        
        // Case 1: Odd number of '?'
        if((lQCount + rQCount) % 2 == 1){
            return true;
        }
        
        // Case 2: Even number of '?'
        int minQCount = min(lQCount, rQCount);
        lQCount -= minQCount;
        rQCount -= minQCount;
        return (lDigitSum + 9 * lQCount / 2 != rDigitSum + 9 * rQCount / 2);
    }
};