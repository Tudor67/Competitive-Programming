class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long targetOps = 1; targetOps <= 40; ++targetOps){
            long long x = num1 - targetOps * num2;
            long long minValidOps = popcount((unsigned long long)x);
            long long maxValidOps = x;
            if(minValidOps <= targetOps && targetOps <= maxValidOps){
                return targetOps;
            }
        }
        return -1;
    }
};