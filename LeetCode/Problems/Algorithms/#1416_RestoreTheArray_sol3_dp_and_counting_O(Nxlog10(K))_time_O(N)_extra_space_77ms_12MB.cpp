class Solution {
private:
    long long stoll(const string& S, const int& L, const int& R){
        long long num = 0;
        for(int i = L; i <= R; ++i){
            num = num * 10 + (S[i] - '0');
        }
        return num;
    }

public:
    int numberOfArrays(string s, int k) {
        const int N = s.length();
        const int K_LEN = 1 + floor(log10((long double)k));
        const int MODULO = 1e9 + 7;

        // dp[i]: number of valid arrays for s[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        for(int i = N - 1; i >= 0; --i){
            if(s[i] == '0'){
                continue;
            }

            for(int j = i; j <= min(i + K_LEN - 2, N - 1); ++j){
                dp[i] = (dp[i] + dp[j + 1]) % MODULO;
            }
            
            if(i + K_LEN - 1 < N && stoll(s, i, i + K_LEN - 1) <= k){
                dp[i] = (dp[i] + dp[i + K_LEN]) % MODULO;
            }
        }

        return dp[0];
    }
};