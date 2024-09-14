class Solution {
public:
    int minBitFlips(int start, int goal) {
        int totalFlips = 0;
        int mask = start ^ goal;
        while(mask > 0){
            mask &= (mask - 1);
            totalFlips += 1;
        }
        return totalFlips;
    }
};