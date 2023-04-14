class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();

        // dp[i][j]: length of the longest palindromic subsequence of s[i .. j]
        vector<vector<int>> dp(N, vector<int>(N));
        for(int i = 0; i < N; ++i){
            dp[i][i] = 1;
        }

        for(int len = 2; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }else{
                    dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i + 1][j]});
                }
            }
        }

        return dp[0][N - 1];
    }
};