class Solution {
public:
    int commonFactors(int a, int b) {
        const int MIN_NUM = min(a, b);
        
        int commonFactors = 0;
        for(int x = 1; x <= MIN_NUM; ++x){
            if(a % x == 0 && b % x == 0){
                commonFactors += 1;
            }
        }
        
        return commonFactors;
    }
};