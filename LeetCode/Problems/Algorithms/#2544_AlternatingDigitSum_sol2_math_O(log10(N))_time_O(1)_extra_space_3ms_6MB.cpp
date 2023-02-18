class Solution {
private:
    int countDigits(int num){
        if(num == 0){
            return 1;
        }

        int digits = 0;
        while(num > 0){
            digits += 1;
            num /= 10;
        }

        return digits;
    }

public:
    int alternateDigitSum(int n) {
        int res = 0;

        int sign = 1;
        if(countDigits(n) % 2 == 0){
            sign = -1;
        }

        while(n > 0){
            res += sign * (n % 10);
            n /= 10;
            sign *= -1;
        }

        return res;
    }
};