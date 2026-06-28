class Solution {
private:
    bool isWavy(int a, int b, int c){
        return (a < b && b > c) ||
               (a > b && b < c);
    }

    long long totalWaviness(const long long N){
        if(N < 100){
            return 0;
        }

        const string S = to_string(N + 1);
        const int S_LEN = S.length();

        vector<long long> pow10(S_LEN + 1, 1);
        for(int i = 1; i <= S_LEN; ++i){
            pow10[i] = pow10[i - 1] * 10;
        }

        // dp[a][b][len]: sum of waviness over every length-len digit string
        //                whose first two digits are (a, b)
        vector<vector<vector<long long>>> dp(10, vector<vector<long long>>(10, vector<long long>(S_LEN + 1)));
        for(int len = 3; len <= S_LEN; ++len){
            for(int a = 0; a <= 9; ++a){
                for(int b = 0; b <= 9; ++b){
                    for(int c = 0; c <= 9; ++c){
                        dp[a][b][len] += dp[b][c][len - 1];
                        if(isWavy(a, b, c)){
                            dp[a][b][len] += pow10[len - 3];
                        }
                    }
                }
            }
        }

        long long res = 0;
        for(int a = 1; a <= 9; ++a){
            for(int b = 0; b <= 9; ++b){
                for(int len = 3; len <= S_LEN - 1; ++len){
                    res += dp[a][b][len];
                }
            }
        }

        long long prefWaviness = 0;
        for(int i = 0; i < S_LEN; ++i){
            int rLen = S_LEN - 1 - i;
            for(int b = (i == 0 ? 1 : 0); b < S[i] - '0'; ++b){
                res += prefWaviness * pow10[rLen];
                
                if(i >= 2 && isWavy(S[i - 2] - '0', S[i - 1] - '0', b)){
                    res += pow10[rLen];
                }

                for(int c = 0; c <= 9; ++c){
                    for(int d = 0; d <= 9; ++d){
                        res += dp[c][d][rLen];
                        
                        if(isWavy(b, c, d) && rLen >= 2){
                            res += pow10[rLen - 2];
                        }
                    }

                    if(i >= 1 && rLen - 1 >= 0){
                        int a = S[i - 1] - '0';
                        if(isWavy(a, b, c)){
                            res += pow10[rLen - 1];
                        }
                    }
                }
            }

            if(i >= 2 && isWavy(S[i - 2] - '0', S[i - 1] - '0', S[i] - '0')){
                prefWaviness += 1;
            }
        }

        return res;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return totalWaviness(num2) - totalWaviness(num1 - 1);
    }
};