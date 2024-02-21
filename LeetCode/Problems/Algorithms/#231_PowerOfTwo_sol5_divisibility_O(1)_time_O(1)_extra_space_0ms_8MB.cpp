class Solution {
public:
    bool isPowerOfTwo(int n) {
        static const int MAX_POW_OF_2 = (1 << 30);
        return (n >= 1 && MAX_POW_OF_2 % n == 0);
    }
};