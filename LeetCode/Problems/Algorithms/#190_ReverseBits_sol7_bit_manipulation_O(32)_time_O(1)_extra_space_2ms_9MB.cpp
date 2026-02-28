class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int bit = 0; bit <= 31; ++bit){
            if((n >> bit) & 1){
                res |= 1 << (31 - bit);
            }
        }
        return res;
    }
};