class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int carryBitVal = 0;
        for(int bit = 0; bit <= 31; ++bit){
            int aBitVal = (a >> bit) & 1;
            int bBitVal = (b >> bit) & 1;
            int cBitVal = (aBitVal ^ bBitVal ^ carryBitVal);
            carryBitVal = (aBitVal & bBitVal) | (aBitVal & carryBitVal) | (bBitVal & carryBitVal);
            c |= (cBitVal << bit);
        }
        return c;
    }
};