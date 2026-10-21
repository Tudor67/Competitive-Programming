class Solution {
public:
    int numDistinct(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();

        // dp[i][j]: number of distinct subsequences of s[i .. S_LEN - 1]
        //           which equals t[j .. T_LEN - 1]
        vector<vector<int>> dp(S_LEN + 1, vector<int>(T_LEN + 1));

        for(int i = S_LEN; i >= 0; --i){
            dp[i][T_LEN] = 1;
        }

        for(int i = S_LEN - 1; i >= 0; --i){
            for(int j = T_LEN - 1; j >= 0; --j){
                dp[i][j] = dp[i + 1][j];
                if(s[i] == t[j] && dp[i][j] <= INT_MAX - dp[i + 1][j + 1]){
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};