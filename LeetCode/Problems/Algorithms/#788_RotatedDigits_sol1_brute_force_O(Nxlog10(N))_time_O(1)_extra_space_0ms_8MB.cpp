class Solution {
private:
    bool isGood(int num){
        bool hasChanged = false;
        while(num > 0){
            int digit = num % 10;
            if(digit == 3 || digit == 4 || digit == 7){
                return false;
            }
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                hasChanged = true;
            }
            num /= 10;
        }
        return hasChanged;
    }

public:
    int rotatedDigits(int n) {
        int goodNums = 0;
        for(int num = 1; num <= n; ++num){
            if(isGood(num)){
                ++goodNums;
            }
        }
        return goodNums;
    }
};