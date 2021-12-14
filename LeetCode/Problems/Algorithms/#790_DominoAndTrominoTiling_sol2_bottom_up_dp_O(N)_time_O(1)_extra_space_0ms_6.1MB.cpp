class Solution {
public:
    int numTilings(int N) {
        const int MODULO = 1e9 + 7;
        
        // We have a board of size 2 x n, such that:
        //    board[1][1 .. n] is the first row of the board;
        //    board[2][1 .. n] is the second row of the board;
        
        // At step i:
        // dp[i % 3][1]: number of ways to tile an 2 x i board such that board[1][i] is not covered and board[2][i] is covered
        // dp[i % 3][2]: number of ways to tile an 2 x i board such that board[1][i] is covered and board[2][i] is not covered
        // dp[i % 3][3]: number of ways to tile an 2 x i board such that board[1][i] is covered and board[2][i] is covered
        vector<vector<long long>> dp(3, vector<long long>(4));
        dp[1][3] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[2][3] = 2;
        for(int i = 3; i <= N; ++i){
            dp[i % 3][3] = (dp[(i - 1) % 3][1] + dp[(i - 1) % 3][2] + dp[(i - 1) % 3][3] + dp[(i - 2) % 3][3]) % MODULO;
            dp[i % 3][1] = (dp[(i - 1) % 3][2] + dp[(i - 2) % 3][3]) % MODULO;
            dp[i % 3][2] = (dp[(i - 1) % 3][1] + dp[(i - 2) % 3][3]) % MODULO;
        }
        
        return dp[N % 3][3];
    }
};