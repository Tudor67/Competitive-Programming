class Solution {
public:
    int kInversePairs(int N, int K) {
        const int MODULO = 1e9 + 7;

        // At Nth iteration:
        //    dp[N % 2][K]: number of different arrays consisting of numbers from 1 to N
        //                  such that there are exactly K inverse pairs
        vector<vector<int>> dp(2, vector<int>(K + 1));
        dp[1][0] = 1;
        for(int i = 2; i <= N; ++i){
            int wSize = i;
            int wSum = 0;
            for(int j = 0; j <= K; ++j){
                wSum = (wSum + dp[(i - 1) % 2][j]) % MODULO;
                if(j >= wSize){
                    wSum = (wSum - dp[(i - 1) % 2][j - wSize] + MODULO) % MODULO;
                }
                dp[i % 2][j] = wSum;
            }
        }

        return dp[N % 2][K];
    }
};