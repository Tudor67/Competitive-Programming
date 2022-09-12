class Solution {
public:
    bool isPalindrome(int x) {
        // Case 1: negative values => return false
        if(x < 0){
            return false;
        }
        
        // Case 2: check if (x == xRev)
        //         avoid overflow when computing xRev
        int xRev = 0;
        for(int val = x; val > 0; val /= 10){
            if(xRev > INT_MAX / 10){
                return false;
            }
            xRev = xRev * 10 + (val % 10);
        }
        
        return (x == xRev);
    }
};