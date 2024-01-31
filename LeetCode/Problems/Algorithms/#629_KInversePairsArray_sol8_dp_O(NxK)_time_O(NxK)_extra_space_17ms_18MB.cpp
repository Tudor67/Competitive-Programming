class Solution {
public:
    int kInversePairs(int N, int K) {
        const int MODULO = 1e9 + 7;

        // dp[N][K]: number of different arrays consisting of numbers from 1 to N
        //           such that there are exactly K inverse pairs
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));
        dp[1][0] = 1;
        for(int i = 2; i <= N; ++i){
            int wSize = i;
            int wSum = 0;
            for(int j = 0; j <= K; ++j){
                wSum = (wSum + dp[i - 1][j]) % MODULO;
                if(j >= wSize){
                    wSum = (wSum - dp[i - 1][j - wSize] + MODULO) % MODULO;
                }
                dp[i][j] = wSum;
            }
        }

        return dp[N][K];
    }
};