class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for(int bit = 0; bit <= 30; ++bit){
            int blockSize = (1 << bit);
            int leftBlock = left / blockSize;
            int rightBlock = right / blockSize;
            if(((left >> bit) & 1) && (leftBlock == rightBlock)){
                res |= (1 << bit);
            }
        }
        return res;
    }
};