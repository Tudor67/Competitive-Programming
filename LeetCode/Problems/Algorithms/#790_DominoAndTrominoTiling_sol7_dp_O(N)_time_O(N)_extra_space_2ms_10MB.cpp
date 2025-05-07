class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int numTilings(int n) {
        const int MODULO = 1'000'000'007;

        // dp[mask][i]: number of ways to tile a 2 x i board
        //              when the configuration of the last column of the board
        //              corresponds to the bitmask mask
        //              (a cell is covered only if the corresponding bit is set)
        vector<vector<int>> dp(4, vector<int>(n + 1));
        dp[3][0] = 1;
        dp[3][1] = 1;

        for(int i = 2; i <= n; ++i){
            add(dp[1][i], dp[2][i - 1], MODULO);
            add(dp[1][i], dp[3][i - 2], MODULO);
            
            add(dp[2][i], dp[1][i - 1], MODULO);
            add(dp[2][i], dp[3][i - 2], MODULO);

            add(dp[3][i], dp[3][i - 2], MODULO);
            add(dp[3][i], dp[3][i - 1], MODULO);
            add(dp[3][i], dp[1][i - 1], MODULO);
            add(dp[3][i], dp[2][i - 1], MODULO);
        }

        return dp[3][n];
    }
};