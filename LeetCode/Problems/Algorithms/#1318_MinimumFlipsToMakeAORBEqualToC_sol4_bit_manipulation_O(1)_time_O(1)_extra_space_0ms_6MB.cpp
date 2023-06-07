class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips1 = __builtin_popcount((a | b) ^ c);
        int flips2 = __builtin_popcount(a & b & (c ^ INT_MAX));
        return flips1 + flips2;
    }
};