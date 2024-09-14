class Solution {
public:
    int minBitFlips(int start, int goal) {
        return popcount((unsigned int)(start ^ goal));
    }
};