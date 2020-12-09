class Solution {
public:
    bool hasAlternatingBits(int N) {
        return __builtin_popcount((uint)N + (N >> 1) + 1) == 1;
    }
};