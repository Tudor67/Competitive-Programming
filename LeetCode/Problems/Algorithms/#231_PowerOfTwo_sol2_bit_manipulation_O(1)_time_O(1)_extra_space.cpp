class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n >= 1 && ((n & (n - 1)) == 0));
    }
};