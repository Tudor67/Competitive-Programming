class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int prevBit1 = 70;
        int bit1 = 70;
        while(n > 0){
            bit1 = __builtin_ctz((unsigned int)n);
            maxGap = max(maxGap, bit1 - prevBit1);
            prevBit1 = bit1;
            n &= (n - 1);
        }
        return maxGap;
    }
};