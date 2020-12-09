class Solution {
public:
    int minFlips(int a, int b, int c) {
        const int MASK1 = (c ^ (a | b));
        const int MASK2 = (c ^ (a | b)) & (a & b);
        int flips = __builtin_popcount(MASK1) + __builtin_popcount(MASK2);
        return flips;
    }
};