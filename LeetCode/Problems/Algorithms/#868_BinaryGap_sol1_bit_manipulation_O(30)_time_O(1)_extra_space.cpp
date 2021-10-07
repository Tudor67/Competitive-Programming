class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int prevBit1 = 50;
        for(int bit = 0; bit <= 30; ++bit){
            if((n >> bit) & 1){
                maxGap = max(maxGap, bit - prevBit1);
                prevBit1 = bit;
            }
        }
        return maxGap;
    }
};