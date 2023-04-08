class Solution {
public:
    long long coloredCells(int n) {
        return n * 1LL * n + (n - 1LL) * (n - 1LL);
    }
};