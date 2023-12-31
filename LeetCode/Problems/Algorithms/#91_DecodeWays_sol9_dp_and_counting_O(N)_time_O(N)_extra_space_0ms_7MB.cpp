class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();

        // dp[i]: number of ways to decode s[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;
        if(s[N - 1] >= '1'){
            dp[N - 1] = 1;
        }

        for(int i = N - 2; i >= 0; --i){
            if(s[i] >= '1' && dp[i] <= INT_MAX - dp[i + 1]){
                dp[i] += dp[i + 1];
            }
            if(s[i] >= '1' && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 && dp[i] <= INT_MAX - dp[i + 2]){
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};