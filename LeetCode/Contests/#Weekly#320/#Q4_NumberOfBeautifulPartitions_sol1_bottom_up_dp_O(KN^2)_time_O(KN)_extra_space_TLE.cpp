class Solution {
private:
    bool isPrime(char c){
        return (c == '2' || c == '3' || c == '5' || c == '7');
    }

public:
    int beautifulPartitions(string s, int k, int minLength) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;

        // Special case
        if(k * minLength > N || !isPrime(s[0]) || isPrime(s[N - 1])){
            return 0;
        }

        // DP
        // dp[i][j]: number of ways to partition s[0 .. i] in j valid parts
        vector<vector<int>> dp(N, vector<int>(k + 1));
        for(int i = minLength - 1; i < N; ++i){
            if(isPrime(s[0]) && !isPrime(s[i])){
                dp[i][1] = 1;
            }
        }

        for(int j = 2; j <= k; ++j){
            for(int i = 1; i < N; ++i){
                if(!isPrime(s[i])){
                    for(int prevI = (j - 1) * minLength; prevI + minLength - 1 <= i; ++prevI){
                        if(isPrime(s[prevI])){
                            dp[i][j] = (dp[i][j] + dp[prevI - 1][j - 1]) % MODULO;
                        }
                    }
                }
            }
        }

        return dp[N - 1][k];
    }
};