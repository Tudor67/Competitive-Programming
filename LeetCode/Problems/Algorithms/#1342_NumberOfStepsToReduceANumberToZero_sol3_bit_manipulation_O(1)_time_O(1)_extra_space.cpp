class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0){
            return 0;
        }
        int bits1 = __builtin_popcount((unsigned int)num); // number of subtractions
        int msb1 = 31 - __builtin_clz((unsigned int)num);  // number of divisions
        return bits1 + msb1;
    }
};