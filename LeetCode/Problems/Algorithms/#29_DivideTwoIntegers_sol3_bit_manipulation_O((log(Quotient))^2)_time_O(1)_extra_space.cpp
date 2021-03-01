class Solution {
private:
    int sign(int num){
        if(num < 0){
            return -1;
        }else if(num > 0){
            return 1;
        }
        return 1;
    }
    
public:
    int divide(int dividend, int divisor) {
        int result = INT_MAX;
        if(dividend == INT_MIN && divisor == 1){
            result = INT_MIN;
        }else if(dividend == INT_MIN && divisor == -1){
            result = INT_MAX;
        }else if(dividend == INT_MIN && divisor == INT_MIN){
            result = 1;
        }else if(divisor == INT_MIN){
            result = 0;
        }else{
            int a = 0;
            int b = 0;
            result = 0;
            if(dividend == INT_MIN){
                a = abs(dividend + abs(divisor));
                b = abs(divisor);
                result = 1;
            }else{
                a = abs(dividend);
                b = abs(divisor);
                result = 0;
            }
            while(a >= b){
                int shift = 0;
                while((a >> (shift + 1)) >= b){
                    shift += 1;
                }
                a -= (b << shift);
                result += (1 << shift);
            }
            if(sign(dividend) != sign(divisor)){
                result = -result;
            }
        }
        return result;
    }
};