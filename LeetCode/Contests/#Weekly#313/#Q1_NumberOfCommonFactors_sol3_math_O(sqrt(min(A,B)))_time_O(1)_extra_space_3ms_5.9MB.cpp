class Solution {
public:
    int commonFactors(int a, int b) {
        const int GCD = gcd(a, b);
        
        int commonFactors = 0;
        for(int x = 1; x * x <= GCD; ++x){
            if(GCD % x == 0){
                commonFactors += 1;
                if(x != GCD / x){
                    commonFactors += 1;
                }
            }
        }
        
        return commonFactors;
    }
};