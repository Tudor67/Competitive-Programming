class Solution {
private:
    int sign(int num){
        if(num < 0){
            return -1;
        }else if(num > 0){
            return 1;
        }
        return 0;
    }
    
public:
    int divide(int dividend, int divisor) {
        int resultSign = sign(dividend) * sign(divisor);
        int result = INT_MAX;
        
        if(dividend == INT_MIN){
            if(divisor == INT_MIN){
                result = 1;
            }else if(divisor == 1){
                result = INT_MIN;
            }else{
                divisor = -abs(divisor);
                int l = 0;
                int r = INT_MAX;
                while(l != r){
                    bool toRight = (r - l) % 2;
                    int mid = l + (r - l) / 2 + toRight;
                    if(INT_MIN / mid <= divisor){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                result = resultSign * r;
            }
        }else if(divisor == INT_MIN){
            result = 0;
        }else{
            dividend = abs(dividend);
            divisor = abs(divisor);
            int l = 0;
            int r = dividend;
            while(l != r){
                bool toRight = (r - l) % 2;
                int mid = l + (r - l) / 2 + toRight;
                if(divisor > dividend / mid){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
            result = resultSign * r;
        }
        
        return result;
    }
};