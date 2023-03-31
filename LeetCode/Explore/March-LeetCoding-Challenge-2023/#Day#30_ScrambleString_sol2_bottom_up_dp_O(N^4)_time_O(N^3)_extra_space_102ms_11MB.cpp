class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.length();

        // dp[len][i][j]: true, if we can scramble s1[i .. i + len - 1] to get s2[j .. j + len - 1]
        //                false, otherwise
        vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                dp[1][i][j] = (bool)(s1[i] == s2[j]);
            }
        }

        for(int len = 2; len <= N; ++len){
            for(int splitLen = 1; splitLen < len; ++splitLen){
                for(int i = 0; i + splitLen < N; ++i){
                    for(int j = 0; j < N; ++j){
                        if(j + splitLen < N && dp[splitLen][i][j] && dp[len - splitLen][i + splitLen][j + splitLen]){
                            dp[len][i][j] = true;
                        }
                        if(j + len - splitLen < N && dp[splitLen][i][j + len - splitLen] && dp[len - splitLen][i + splitLen][j]){
                            dp[len][i][j] = true;
                        }
                    }
                }
            }
        }

        return dp[N][0][0];
    }
};