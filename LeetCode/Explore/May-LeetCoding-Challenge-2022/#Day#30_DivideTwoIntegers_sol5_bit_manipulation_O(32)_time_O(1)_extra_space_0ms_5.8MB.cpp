class Solution {
private:
    int sign(int num){
        if(num < 0){
            return -1;
        }
        if(num > 0){
            return 1;
        }
        return 0;
    }
    
public:
    int divide(int dividend, int divisor) {
        // Special cases
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        if(dividend == INT_MIN && divisor == INT_MIN){
            return 1;
        }
        
        if(dividend != INT_MIN && divisor == INT_MIN){
            return 0;
        }
        
        // Avoid abs(dividend) when dividend = INT_MIN (we already have (divisor > INT_MIN)):
        //       convert (dividend / divisor) to ((dividend + abs(divisor)) / divisor - sign(divisor)
        int extra = 0;
        if(dividend == INT_MIN){
            extra = sign(divisor);
            dividend += abs(divisor);
        }
        
        int quotientSign = sign(dividend) * sign(divisor);
        int quotientAbs = 0;
        
        int dividendAbs = abs(dividend);
        int divisorAbs = abs(divisor);
        for(int bit = 30; bit >= 0; --bit){
            if(divisorAbs <= (dividendAbs >> bit)){
                quotientAbs |= (1 << bit);
                dividendAbs -= (divisorAbs << bit);
            }
        }
        
        return quotientSign * quotientAbs - extra;
    }
};