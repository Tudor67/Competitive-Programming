class Solution {
public:
    int reverse(int x) {
        // Case 1: special case
        if(x == INT_MIN){
            return 0;
        }
        
        // Case 2: reverse the absolute value of x
        int sign = (x < 0 ? -1 : 1);
        int xAbs = (x < 0 ? -x : x);
        int xAbsRev = 0;
        while(xAbs > 0){
            if(xAbsRev > INT_MAX / 10){
                return 0;
            }
            xAbsRev = xAbsRev * 10 + (xAbs % 10);
            xAbs /= 10;
        }
        
        return sign * xAbsRev;
    }
};