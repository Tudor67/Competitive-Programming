class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0;
        
        int sign = 1;
        string numStr = to_string(n);
        for(char c: numStr){
            res += sign * (c - '0');
            sign *= -1;
        }

        return res;
    }
};