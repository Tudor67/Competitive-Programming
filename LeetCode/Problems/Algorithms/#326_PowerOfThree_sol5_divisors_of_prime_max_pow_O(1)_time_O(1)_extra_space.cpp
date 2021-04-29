class Solution {
public:
    bool isPowerOfThree(int n) {
        const int MAX_3_POW = 1162261467; // 3 ^ 19
        return (0 < n && MAX_3_POW % n == 0);
    }
};