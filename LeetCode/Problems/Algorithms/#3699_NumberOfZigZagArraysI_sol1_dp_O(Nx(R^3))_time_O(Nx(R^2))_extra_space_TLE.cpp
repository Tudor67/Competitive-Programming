class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MODULO = 1'000'000'007;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(r + 1, vector<int>(r + 1)));

        for(int a = l; a <= r; ++a){
            for(int b = l; b <= r; ++b){
                dp[2][a][b] = 1;
            }
        }

        for(int len = 3; len <= n; ++len){
            for(int c = l; c <= r; ++c){
                for(int b = l; b <= r; ++b){
                    for(int a = l; a <= r; ++a){
                        if((a == b) || (b == c) || (a < b && b < c) || (a > b && b > c)){
                            continue;
                        }
                        dp[len][b][c] += dp[len - 1][a][b];
                        dp[len][b][c] %= MODULO;
                    }
                }
            }
        }

        int res = 0;
        for(int a = l; a <= r; ++a){
            for(int b = l; b <= r; ++b){
                res += dp[n][a][b];
                res %= MODULO;
            }
        }

        return res;
    }
};