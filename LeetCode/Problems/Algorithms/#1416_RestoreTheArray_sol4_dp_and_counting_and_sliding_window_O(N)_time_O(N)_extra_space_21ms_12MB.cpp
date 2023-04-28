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
        const long long K_MAX_POW = pow((long double)10, (long double)K_LEN - 1);
        const int MODULO = 1e9 + 7;

        // dp[i]: number of valid arrays for s[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        // truncNum = int value of s[i .. i + K_LEN - 1]
        // truncNumMaxPow = power of the current most significant digit
        // truncNumMaxPow <= K_MAX_POW
        long long truncNum = 0;
        long long truncNumMaxPow = 1;

        // windowSum = (dp[i + 1] + ... + dp[i + K_LEN - 1]) % MODULO
        int windowSum = 0;
        if(K_LEN >= 2){
            windowSum = dp[N];
        }

        for(int i = N - 1; i >= 0; --i){
            if(K_LEN < N - i){
                truncNum /= 10;
            }
            truncNum = (s[i] - '0') * truncNumMaxPow + truncNum;
            truncNumMaxPow = min(truncNumMaxPow * 10, K_MAX_POW);

            if(s[i] != '0'){
                dp[i] = (dp[i] + windowSum) % MODULO;
                if(i + K_LEN - 1 < N && truncNum <= k){
                    dp[i] = (dp[i] + dp[i + K_LEN]) % MODULO;
                }
            }

            windowSum = (windowSum + dp[i]) % MODULO;
            if(i + K_LEN - 2 < N){
                windowSum = (windowSum - dp[i + K_LEN - 1] + MODULO) % MODULO;
            }
        }

        return dp[0];
    }
};