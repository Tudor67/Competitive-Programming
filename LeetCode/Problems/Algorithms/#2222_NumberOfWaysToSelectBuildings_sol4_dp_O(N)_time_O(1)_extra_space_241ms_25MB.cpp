class Solution {
public:
    long long numberOfWays(string s) {
        const int N = s.length();
        const int K = 3;
        
        // dp[len][val]: number of alternating subsequences of length len and with last value equal to val
        vector<vector<long long>> dp(K + 1, vector<long long>(2));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 0; i < N; ++i){
            for(int len = 1; len <= K; ++len){
                dp[len][s[i] - '0'] += dp[len - 1][1 - (s[i] - '0')];
            }
        }
        
        return (dp[K][0] + dp[K][1]);
    }
};