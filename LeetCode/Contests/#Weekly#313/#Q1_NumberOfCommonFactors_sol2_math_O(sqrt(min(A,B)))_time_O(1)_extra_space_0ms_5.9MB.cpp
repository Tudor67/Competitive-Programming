class Solution {
public:
    int commonFactors(int a, int b) {
        int limit = gcd(a, b);
        
        int commonFactors = 1;
        int x = 2;
        while(x * x <= limit){
            if(limit % x == 0){
                int primePow = 0;
                while(limit % x == 0){
                    limit /= x;
                    primePow += 1;
                }
                commonFactors *= (primePow + 1);
            }
            x += 1;
        }
        
        if(limit > 1){
            commonFactors *= 2;
        }
        
        return commonFactors;
    }
};