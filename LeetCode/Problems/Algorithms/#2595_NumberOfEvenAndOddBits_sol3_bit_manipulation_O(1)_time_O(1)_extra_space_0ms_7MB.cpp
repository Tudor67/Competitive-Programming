class Solution {
public:
    vector<int> evenOddBit(int n) {
        return {__builtin_popcount(n & 0b0101010101),
                __builtin_popcount(n & 0b1010101010)};
    }
};