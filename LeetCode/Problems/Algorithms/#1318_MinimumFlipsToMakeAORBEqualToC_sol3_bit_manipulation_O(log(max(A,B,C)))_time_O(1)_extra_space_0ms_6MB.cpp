class Solution {
public:
    int minFlips(int a, int b, int c) {
        const int MAX_BIT = floor(log2(max({a, b, c})));

        int flips = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int aBitVal = (a >> bit) & 1;
            int bBitVal = (b >> bit) & 1;
            int cBitVal = (c >> bit) & 1;
            if((aBitVal | bBitVal) != cBitVal){
                if(cBitVal == 1){
                    flips += 1;
                }else{
                    flips += (int)(aBitVal == 1) + (int)(bBitVal == 1);
                }
            }
        }

        return flips;
    }
};