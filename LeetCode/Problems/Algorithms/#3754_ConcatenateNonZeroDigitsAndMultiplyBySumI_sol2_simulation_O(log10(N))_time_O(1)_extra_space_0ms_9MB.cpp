class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long xPow10 = 1;
        long long sum = 0;

        while(n > 0){
            int digit = n % 10;
            if(digit > 0){
                x += digit * xPow10;
                xPow10 *= 10;
                sum += digit;
            }
            n /= 10;
        }

        return x * sum;
    }
};