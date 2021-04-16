/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is lower than the guess number
 *                1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // Step 0: avoid future overflow problems
        if(guess(n) == 0){
            return n;
        }
        
        // Step 1: ternary search on ranges with length >= 3
        int l = 1;
        int r = n - 1;
        while(r - l + 1 >= 3){
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            int mid1Guess = guess(mid1);
            int mid2Guess = guess(mid2);
            if(mid1Guess == 0){
                l = mid1;
                r = mid1;
            }else if(mid1Guess == -1){
                r = mid1 - 1;
            }else if(mid1Guess == 1){
                if(mid2Guess == 0){
                    l = mid2;
                    r = mid2;
                }else if(mid2Guess == -1){
                    l = mid1 + 1;
                    r = mid2 - 1;
                }else if(mid2Guess == 1){
                    l = mid2 + 1;
                }
            }
        }
        
        // Step 2: update answer
        int answer = -1;
        for(int i = l; i <= r; ++i){
            if(guess(i) == 0){
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};