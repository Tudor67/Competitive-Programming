class Solution {
public:
    int smallestNumber(int n) {
        int msb = 31 - __builtin_clz((unsigned int)n);
        return (1 << (msb + 1)) - 1;
    }
};