class Solution {
private:
    int remap(int num, int d1, int d2){
        int res = 0;
        int mult = 1;
        while(num > 0){
            int digit = num % 10;
            if(digit == d1){
                res = d2 * mult + res;
            }else{
                res = digit * mult + res;
            }
            num /= 10;
            mult *= 10;
        }
        return res;
    }

public:
    int minMaxDifference(int num) {
        int minNum = num;
        int maxNum = num;
        for(int d1 = 0; d1 <= 9; ++d1){
            for(int d2: {0, 9}){
                int newNum = remap(num, d1, d2);
                minNum = min(minNum, newNum);
                maxNum = max(maxNum, newNum);
            }
        }
        return maxNum - minNum;
    }
};