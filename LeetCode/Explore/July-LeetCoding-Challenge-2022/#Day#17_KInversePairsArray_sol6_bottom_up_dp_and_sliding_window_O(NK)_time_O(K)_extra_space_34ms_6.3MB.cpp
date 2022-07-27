class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MODULO = 1e9 + 7;
        
        // At nth iteration:
        //    dp[n % 2][k]: number of different arrays consisting of numbers from 1 to n
        //                  such that there are exactly k inverse pairs
        vector<vector<int>> dp(2, vector<int>(k + 1));
        
        dp[1][0] = 1;
        for(int i = 2; i <= n; ++i){
            int sum = 0;
            for(int j = 0; j <= k; ++j){
                sum += dp[(i - 1) % 2][j];
                sum %= MODULO;
                if(j >= i){
                    sum -= dp[(i - 1) % 2][j - i];
                    sum += MODULO;
                    sum %= MODULO;
                }
                dp[i % 2][j] = sum;
            }
        }
        
        return dp[n % 2][k];
    }
};