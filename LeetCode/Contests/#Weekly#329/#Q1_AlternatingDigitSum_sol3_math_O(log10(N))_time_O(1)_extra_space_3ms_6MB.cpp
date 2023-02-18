class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0;

        int sign = 1;
        while(n > 0){
            sign *= -1;
            res += sign * (n % 10);
            n /= 10;
        }

        return sign * res;
    }
};