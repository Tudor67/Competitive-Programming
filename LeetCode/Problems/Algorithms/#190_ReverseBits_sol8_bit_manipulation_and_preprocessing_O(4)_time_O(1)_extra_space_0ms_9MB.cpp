class Solution {
private:
    static constexpr array<int, 256> reverseOf = [](){
        array<int, 256> reverseOf;
        for(int i = 0; i < 256; ++i){
            int x = i;
            x = ((x & 0b11110000) >> 4) | ((x & 0b00001111) << 4);
            x = ((x & 0b11001100) >> 2) | ((x & 0b00110011) << 2);
            x = ((x & 0b10101010) >> 1) | ((x & 0b01010101) << 1);
            reverseOf[i] = x;
        }
        return reverseOf;
    }();

public:
    int reverseBits(int n) {
        int res = 0;
        for(int block = 0; block < 4; ++block){
            res = (res << 8) | reverseOf[n & 255];
            n >>= 8;
        }
        return res;
    }
};