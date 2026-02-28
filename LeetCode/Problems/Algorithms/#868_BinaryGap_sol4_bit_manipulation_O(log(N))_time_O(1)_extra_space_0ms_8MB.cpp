class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        int prevBit = 31;
        for(int currBit = 0; (1 << currBit) <= n; ++currBit){
            if((n >> currBit) & 1){
                maxDist = max(maxDist, currBit - prevBit);
                prevBit = currBit;
            }
        }
        return maxDist;
    }
};