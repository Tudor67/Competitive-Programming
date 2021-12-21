class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n >= 1 && (1 << 31) % n == 0;
    }
};