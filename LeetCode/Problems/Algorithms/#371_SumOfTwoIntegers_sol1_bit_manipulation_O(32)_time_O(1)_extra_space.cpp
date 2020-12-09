class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int carryBitVal = 0;
        for(int bit = 0; bit <= 31; ++bit){
            int aBitVal = (a >> bit) & 1;
            int bBitVal = (b >> bit) & 1;
            int cBitVal = 0;
            if((aBitVal & bBitVal) == 0 && (aBitVal | bBitVal) == 0){
                cBitVal = carryBitVal;
                carryBitVal = 0;
            }else if((aBitVal & bBitVal) == 0 && (aBitVal | bBitVal) == 1){
                cBitVal = !carryBitVal;
            }else if((aBitVal & bBitVal) == 1){
                cBitVal = carryBitVal;
                carryBitVal = 1;
            }
            c |= (cBitVal << bit);
        }
        return c;
    }
};