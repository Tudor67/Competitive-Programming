class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        const int MODULO = 1'000'000'007;

        auto add = [&](int& a, int b) -> void {
            a = (a + b) % MODULO;
        };

        auto getRangeSum = [&](vector<int>& prefSum, int l, int r) -> int {
            if(l > r) return 0;
            if(l == 0) return prefSum[r];
            return (prefSum[r] - prefSum[l - 1] + MODULO) % MODULO;
        };

        // dp[0][x][y]: number of stable binary arrays with x zeros, y ones, ending with zero
        // dp[1][x][y]: number of stable binary arrays with x zeros, y ones, ending with one
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(zeros + 1, vector<int>(ones + 1)));
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;

        vector<vector<int>> prefSum0(zeros + 1, vector<int>(ones + 1));
        vector<vector<int>> prefSum1(ones + 1, vector<int>(zeros + 1));
        prefSum0[0][0] = 1;
        prefSum1[0][0] = 1;

        for(int len = 1; len <= zeros + ones; ++len){
            for(int currZeros = 0; currZeros <= min(zeros, len); ++currZeros){
                int currOnes = len - currZeros;
                if(currOnes > ones){
                    continue;
                }

                dp[0][currZeros][currOnes] = getRangeSum(prefSum1[currOnes], max(currZeros - limit, 0), currZeros - 1);
                dp[1][currZeros][currOnes] = getRangeSum(prefSum0[currZeros], max(currOnes - limit, 0), currOnes - 1);

                if(currZeros >= 1){
                    prefSum1[currOnes][currZeros] = prefSum1[currOnes][currZeros - 1];
                }
                add(prefSum1[currOnes][currZeros], dp[1][currZeros][currOnes]);

                if(currOnes >= 1){
                    prefSum0[currZeros][currOnes] = prefSum0[currZeros][currOnes - 1];
                }
                add(prefSum0[currZeros][currOnes], dp[0][currZeros][currOnes]);
            }
        }

        return (dp[0][zeros][ones] + dp[1][zeros][ones]) % MODULO;
    }
};