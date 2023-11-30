class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneBits = 0;
        while(n > 0){
            n &= (n - 1);
            oneBits += 1;
        }
        return oneBits;
    }
};