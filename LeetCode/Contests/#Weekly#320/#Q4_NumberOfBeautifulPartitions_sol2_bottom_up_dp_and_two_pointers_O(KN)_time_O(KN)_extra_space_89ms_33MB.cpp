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
            int pos = 0;
            int prefSumPrevDP = 0;
            for(int i = 1; i < N; ++i){
                if(!isPrime(s[i])){
                    while(pos + 1 + minLength - 1 <= i){
                        pos += 1;
                        if(!isPrime(s[pos - 1]) && isPrime(s[pos])){
                            prefSumPrevDP = (prefSumPrevDP + dp[pos - 1][j - 1]) % MODULO;
                        }
                    }
                    dp[i][j] = prefSumPrevDP;
                }
            }
        }

        return dp[N - 1][k];
    }
};