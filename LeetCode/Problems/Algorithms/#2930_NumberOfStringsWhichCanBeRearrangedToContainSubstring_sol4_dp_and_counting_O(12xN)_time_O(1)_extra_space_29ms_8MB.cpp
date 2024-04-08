class Solution {
public:
    int stringCount(int N) {
        const int MODULO = 1e9 + 7;
        // At Nth iteration:
        // dp[e][l][t][N % 2]: total number of strings with at least e chars equal to 'e',
        //                                                       l chars equal to 'l',
        //                                                       t chars equal to 't',
        //                     and length equal to N
        vector<vector<vector<vector<int>>>> dp(3, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2))));
        dp[0][0][0][0] = 1;
        for(int len = 1; len <= N; ++len){
            for(int e = 0; e <= 2; ++e){
                for(int l = 0; l <= 1; ++l){
                    for(int t = 0; t <= 1; ++t){
                        dp[e][l][t][len % 2] = ((long long)dp[max(0, e - 1)][l][t][(len - 1) % 2] +
                                                (long long)dp[e][max(0, l - 1)][t][(len - 1) % 2] +
                                                (long long)dp[e][l][max(0, t - 1)][(len - 1) % 2] +
                                                23 * (long long)dp[e][l][t][(len - 1) % 2]) % MODULO;
                    }
                }
            }
        }

        return dp[2][1][1][N % 2];
    }
};