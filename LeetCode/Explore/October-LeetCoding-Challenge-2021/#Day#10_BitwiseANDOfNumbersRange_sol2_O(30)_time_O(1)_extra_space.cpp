class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        const int MAX_BIT = 30;
        int rangeAND = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int blockSize = (1 << bit);
            int leftBlock = left / blockSize;
            int rightBlock = right / blockSize;
            if(leftBlock == rightBlock){
                if(rightBlock & 1){
                    rangeAND |= (1 << bit);
                }
            }
        }
        return rangeAND;
    }
};