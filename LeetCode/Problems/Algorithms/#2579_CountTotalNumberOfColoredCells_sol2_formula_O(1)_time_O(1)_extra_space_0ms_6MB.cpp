class Solution {
public:
    long long coloredCells(int n) {
        return 2 * n * (n + 1LL) - 4 * n + 1;
    }
};