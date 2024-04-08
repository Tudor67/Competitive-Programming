class Solution {
private:
    const int MODULO = 1e9 + 7;

    long long countGoodStrings(int l, int e, int t, int n, vector<vector<vector<vector<int>>>>& memo){
        if(n == 0){
            return (l == 0 && e == 0 && t == 0);
        }
        if(memo[l][e][t][n] == -1){
            memo[l][e][t][n] = (countGoodStrings(max(0, l - 1), e, t, n - 1, memo) +
                                countGoodStrings(l, max(0, e - 1), t, n - 1, memo) +
                                countGoodStrings(l, e, max(0, t - 1), n - 1, memo) +
                                23 * countGoodStrings(l, e, t, n - 1, memo)) % MODULO;
        }
        return memo[l][e][t][n];
    }

public:
    int stringCount(int n) {
        vector<vector<vector<vector<int>>>> memo(2, vector<vector<vector<int>>>(3, vector<vector<int>>(2, vector<int>(n + 1, -1))));
        return countGoodStrings(1, 2, 1, n, memo);
    }
};