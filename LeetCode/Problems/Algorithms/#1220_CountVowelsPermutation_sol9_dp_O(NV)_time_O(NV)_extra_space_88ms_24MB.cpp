class Solution {
public:
    int countVowelPermutation(int N) {
        const int V = 5;
        const int MODULO = 1e9 + 7;
        
        // dp[len][j]: number of valid strings of length len
        //             ending with the jth vowel
        vector<vector<int>> dp(N + 1, vector<int>(V));
        for(int j = 0; j < V; ++j){
            dp[1][j] = 1;
        }
        
        int a = 0;
        int e = 1;
        int i = 2;
        int o = 3;
        int u = 4;
        for(int len = 2; len <= N; ++len){
            dp[len][a] = ((dp[len - 1][e] + dp[len - 1][u]) % MODULO + dp[len - 1][i]) % MODULO;
            dp[len][e] = (dp[len - 1][a] + dp[len - 1][i]) % MODULO;
            dp[len][i] = (dp[len - 1][o] + dp[len - 1][e]) % MODULO;
            dp[len][o] = dp[len - 1][i];
            dp[len][u] = (dp[len - 1][o] + dp[len - 1][i]) % MODULO;
        }
        
        int res = 0;
        for(int j = 0; j < V; ++j){
            res += dp[N][j];
            res %= MODULO;
        }
        
        return res;
    }
};