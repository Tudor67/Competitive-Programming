class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0){
            return 0;
        }
        int msb1 = 31 - __builtin_clz((unsigned int)num);
        int bits1 = __builtin_popcount((unsigned int)num);
        return msb1 + bits1;
    }
};