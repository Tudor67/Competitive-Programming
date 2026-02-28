class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        int prevBit = -1;
        int currBit = 0;

        while(n > 0){
            if(n & 1){
                if(prevBit != -1){
                    maxDist = max(maxDist, currBit - prevBit);
                }
                prevBit = currBit;
            }
            n >>= 1;
            currBit += 1;
        }

        return maxDist;
    }
};