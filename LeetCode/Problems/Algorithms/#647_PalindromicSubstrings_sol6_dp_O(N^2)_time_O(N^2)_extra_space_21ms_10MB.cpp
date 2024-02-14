class Solution {
public:
    int countSubstrings(string s) {
        const int N = s.length();

        // dp[i][j] = true,  if s[i .. j] is palindrome
        // dp[i][j] = false, otherwise
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            dp[i][i] = true;
        }

        for(int len = 2; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(s[i] == s[j]){
                    if(len == 2 || dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                }
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                if(dp[i][j]){
                    res += 1;
                }
            }
        }

        return res;
    }
};