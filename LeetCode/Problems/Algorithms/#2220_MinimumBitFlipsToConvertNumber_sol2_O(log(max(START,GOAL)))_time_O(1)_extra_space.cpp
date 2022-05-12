class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        int xorVal = start ^ goal;
        while(xorVal > 0){
            if(xorVal % 2 == 1){
                flips += 1;
            }
            xorVal /= 2;
        }
        return flips;
    }
};