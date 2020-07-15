class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        for(int bit = 0; bit <= 31; ++bit){
            answer = (answer << 1) | (n & 1);
            n >>= 1;
        }
        return answer;
    }
};