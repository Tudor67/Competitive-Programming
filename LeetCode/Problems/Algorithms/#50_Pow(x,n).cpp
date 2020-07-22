class Solution {
public:
    double myPow(double x, int n) {
        long long power = abs((long long)n);
        
        double answer = 1;
        while(power > 0 && answer != 0){
            if(power & 1){
                answer *= x;
            }
            power >>= 1;
            if(power > 0){
                x *= x;
            }
        }
        
        if(n < 0){
            answer = 1 / answer;
        }
        
        return answer;
    }
};