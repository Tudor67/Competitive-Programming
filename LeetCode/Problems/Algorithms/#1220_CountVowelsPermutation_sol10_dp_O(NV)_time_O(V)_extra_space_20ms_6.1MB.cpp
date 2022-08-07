class Solution {
public:
    int countVowelPermutation(int N) {
        const int V = 5;
        const int MODULO = 1e9 + 7;
        
        // At iteration len:
        //    dp[len % 2][j]: number of valid strings of length len
        //                    ending with the jth vowel
        vector<vector<int>> dp(2, vector<int>(V));
        for(int j = 0; j < V; ++j){
            dp[1][j] = 1;
        }
        
        int a = 0;
        int e = 1;
        int i = 2;
        int o = 3;
        int u = 4;
        for(int len = 2; len <= N; ++len){
            dp[len % 2][a] = ((dp[(len - 1) % 2][e] + dp[(len - 1) % 2][u]) % MODULO + dp[(len - 1) % 2][i]) % MODULO;
            dp[len % 2][e] = (dp[(len - 1) % 2][a] + dp[(len - 1) % 2][i]) % MODULO;
            dp[len % 2][i] = (dp[(len - 1) % 2][o] + dp[(len - 1) % 2][e]) % MODULO;
            dp[len % 2][o] = dp[(len - 1) % 2][i];
            dp[len % 2][u] = (dp[(len - 1) % 2][o] + dp[(len - 1) % 2][i]) % MODULO;
        }
        
        int res = 0;
        for(int j = 0; j < V; ++j){
            res += dp[N % 2][j];
            res %= MODULO;
        }
        
        return res;
    }
};