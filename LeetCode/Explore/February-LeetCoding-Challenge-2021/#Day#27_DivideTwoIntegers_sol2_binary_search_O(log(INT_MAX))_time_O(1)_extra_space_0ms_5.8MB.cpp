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
    
    int negativeNum(int num){
        if(num > 0){
            return -num;
        }
        return num;
    }
    
public:
    int divide(int dividend, int divisor) {
        int result = INT_MAX;
        if(divisor == 1){
            result = dividend;
        }else{
            int resultSign = sign(dividend) * sign(divisor);
            dividend = negativeNum(dividend);
            divisor = negativeNum(divisor);
            int l = 0;
            int r = INT_MAX;
            while(l != r){
                int mid = l + (r - l) / 2 + (r - l) % 2;
                if(dividend / mid <= divisor){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            result = resultSign * r;
        }
        return result;
    }
};