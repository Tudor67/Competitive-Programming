class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int prevBit1 = 50;
        int bit = 0;
        while(n > 0){
            if(n & 1){
                maxGap = max(maxGap, bit - prevBit1);
                prevBit1 = bit;
            }
            bit += 1;
            n >>= 1;
        }
        return maxGap;
    }
};