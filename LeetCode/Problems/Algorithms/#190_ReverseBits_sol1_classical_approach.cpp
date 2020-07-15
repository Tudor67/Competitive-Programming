class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        for(int bit = 0; bit <= 31; ++bit){
            if(n & (1UL << bit)){
                answer |= (1UL << (31 - bit));
            }
        }
        return answer;
    }
};