class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int N = s.length();
        const string K_STR = to_string(k);
        const int K_LEN = K_STR.length();
        const int MODULO = 1e9 + 7;

        // dp[i]: number of valid arrays for s[0 .. i]
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            for(int j = max(0, i - K_LEN + 1); j <= i; ++j){
                if(s[j] == '0'){
                    continue;
                }
                int len = i - j + 1;
                if((len < K_LEN) || (len == K_LEN && s.compare(j, len, K_STR, 0, len) <= 0)){
                    if(j == 0){
                        dp[i] += 1;
                        dp[i] %= MODULO;
                    }else{
                        dp[i] += dp[j - 1];
                        dp[i] %= MODULO;
                    }
                }
            }
        }

        return dp[N - 1];
    }
};