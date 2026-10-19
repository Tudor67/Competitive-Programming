class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProduct = 1;
        for(int x = n; x > 0; x /= 10){
            int digit = x % 10;
            digitSum += digit;
            digitProduct *= digit;
        }
        return (n % (digitSum + digitProduct) == 0);
    }
};