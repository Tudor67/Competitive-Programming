class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int digitsSum = 0;
            while(num > 0){
                digitsSum += (num % 10);
                num /= 10;
            }
            num = digitsSum;
        }
        return num;
    }
};