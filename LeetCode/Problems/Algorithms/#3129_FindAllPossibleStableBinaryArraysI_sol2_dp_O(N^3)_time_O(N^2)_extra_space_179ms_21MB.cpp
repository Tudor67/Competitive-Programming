class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        const int MODULO = 1'000'000'007;

        auto add = [&](int& a, int b) -> void {
            a = (a + b) % MODULO;
        };

        // dp[0][x][y]: number of stable binary arrays with x zeros, y ones, ending with zero
        // dp[1][x][y]: number of stable binary arrays with x zeros, y ones, ending with one
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(zeros + 1, vector<int>(ones + 1)));
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;

        for(int len = 1; len <= zeros + ones; ++len){
            for(int currZeros = 0; currZeros <= min(zeros, len); ++currZeros){
                int currOnes = len - currZeros;
                if(currOnes > ones){
                    continue;
                }
                for(int c0 = 1; c0 <= min(currZeros, limit); ++c0){
                    add(dp[0][currZeros][currOnes], dp[1][currZeros - c0][currOnes]);
                }
                for(int c1 = 1; c1 <= min(currOnes, limit); ++c1){
                    add(dp[1][currZeros][currOnes], dp[0][currZeros][currOnes - c1]);
                }
            }
        }

        return (dp[0][zeros][ones] + dp[1][zeros][ones]) % MODULO;
    }
};