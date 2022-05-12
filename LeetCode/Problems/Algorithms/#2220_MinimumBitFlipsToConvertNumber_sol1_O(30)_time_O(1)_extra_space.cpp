class Solution {
public:
    int minBitFlips(int start, int goal) {
        const int MAX_BIT = 30;
        int flips = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int startBitVal = (start >> bit) & 1;
            int goalBitVal = (goal >> bit) & 1;
            if(startBitVal != goalBitVal){
                flips += 1;
            }
        }
        return flips;
    }
};