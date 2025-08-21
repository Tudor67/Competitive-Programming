class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n >= 1 &&
                (n & (n - 1)) == 0 &&
                (0x55555555 & n) == n);
    }
};