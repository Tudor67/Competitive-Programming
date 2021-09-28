class Solution {
public:
    int numDistinct(string initialS, string t) {
        // Step 1: check if t is a subsequence of initialS
        int j = 0;
        for(char c: initialS){
            if(j < (int)t.length() && c == t[j]){
                j += 1;
            }
        }
        
        if(j < (int)t.length()){
            return 0;
        }        

        // Step 2: remove redundant chars from initialS
        vector<bool> exists(128, false);
        for(char c: t){
            exists[c] = true;
        }
        
        string s;
        for(char c: initialS){
            if(exists[c]){
                s += c;
            }
        }
        
        // Step 3: DP (compressed version with only O(M) extra-space)
        // dp[i][j]: number of distinct subsequences of s[1 .. i] which equals t[1 .. j]
        const int N = s.length();
        const int M = t.length();
        
        s = "#" + s;
        t = "#" + t;

        vector<vector<long long>> dp(2, vector<long long>(M + 2));
        dp[0][0] = 1;
        dp[1][0] = 1;
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if(s[i] == t[j]){
                    dp[i % 2][j] += dp[(i - 1) % 2][j - 1];
                }
                // It is guaranteed the answer fits on a 32-bit signed integer => dp[i][j] <= INT_MAX
                dp[i % 2][j] = min(dp[i % 2][j], (long long)INT_MAX);
            }
        }
        
        return dp[N % 2][M];
    }
};