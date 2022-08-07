class Solution {
private:
    long long nCk(int n, int k){
        long long res = 1;
        for(int i = 1; i <= k; ++i){
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }
    
public:
    int uniquePaths(int m, int n) {
        const int ROWS = m;
        const int COLS = n;
        return nCk(ROWS + COLS - 2, min(ROWS, COLS) - 1);
    }
};