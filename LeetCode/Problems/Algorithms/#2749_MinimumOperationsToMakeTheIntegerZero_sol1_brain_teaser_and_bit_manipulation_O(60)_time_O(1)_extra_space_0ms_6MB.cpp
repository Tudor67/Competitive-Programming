class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long ops = 1; ops <= 60; ++ops){
            long long diff = num1 - ops * num2;
            long long minValidOps = __builtin_popcountll(diff);
            long long maxValidOps = diff;
            if(minValidOps <= ops && ops <= maxValidOps){
                return ops;
            }
        }
        return -1;
    }
};