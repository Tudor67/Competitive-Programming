class Solution {
public:
    bool isPalindrome(int x) {
        // Case 1: x is negative => return false
        if(x < 0){
            return false;
        }
        
        // Case 2: x is zero => return true
        if(x == 0){
            return true;
        }
        
        // Case 3: x is strictly positive and the last digit of x is zero => return false
        if(x > 0 && x % 10 == 0){
            return false;
        }
        
        // Case 4: x and its last digit are strictly positive
        // - compute the first half of x: half1
        // - compute the reversed second half of x: half2Rev
        // - check if (half1 == half2Rev) for even length x
        // - check if (half1 == half2Rev / 10) for odd length x
        int half1 = x;
        int half2Rev = 0;
        while(half1 > half2Rev){
            half2Rev = half2Rev * 10 + (half1 % 10);
            half1 /= 10;
        }
        
        return (half1 == half2Rev || half1 == half2Rev / 10);
    }
};