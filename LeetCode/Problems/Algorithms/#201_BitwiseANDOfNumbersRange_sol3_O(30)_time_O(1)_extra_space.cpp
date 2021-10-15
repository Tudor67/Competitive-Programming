class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        const int MAX_BIT = 30;
        int rangeAND = 0;
        for(int bit = MAX_BIT; bit >= 0; --bit){
            int leftBitVal = (left >> bit) & 1;
            int rightBitVal = (right >> bit) & 1;
            if(leftBitVal == rightBitVal){
                if(rightBitVal == 1){
                    rangeAND |= (1 << bit);
                }
            }else{
                break;
            }
        }
        return rangeAND;
    }
};