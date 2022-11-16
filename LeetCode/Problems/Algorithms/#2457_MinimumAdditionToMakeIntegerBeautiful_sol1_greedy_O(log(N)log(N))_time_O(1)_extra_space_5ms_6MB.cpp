class Solution {
private:
    long long computeDigitsSum(long long num){
        long long s = 0;
        while(num > 0){
            s += (num % 10);
            num /= 10;
        }
        return s;
    }
    
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long x = 0;
        long long p10 = 1;
        while(computeDigitsSum(n + x) > target){
            long long digit = ((n + x) / p10) % 10;
            if(digit > 0){
                x = (10 - digit) * p10 + x;
            }
            p10 *= 10;
        }
        return x;
    }
};