class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for(int x = num; x > 0; x /= 10){
            int digit = x % 10;
            if(num % digit == 0){
                res += 1;
            }
        }
        return res;
    }
};