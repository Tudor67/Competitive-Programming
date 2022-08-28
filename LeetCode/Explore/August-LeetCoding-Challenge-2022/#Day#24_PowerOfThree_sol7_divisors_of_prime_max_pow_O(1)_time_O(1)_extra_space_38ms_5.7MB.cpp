class Solution {
public:
    bool isPowerOfThree(int n) {
        const int MAX_POW_OF_3 = 1162261467; // 3^19
        return (n >= 1 && MAX_POW_OF_3 % n == 0);
    }
};