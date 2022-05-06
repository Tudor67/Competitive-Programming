class Solution {
public:
    int minimumWhiteTiles(string s, int numCarpets, int carpetLen) {
        const int N = s.length();
        const int INF = N + 10;
        
        if(numCarpets * carpetLen >= N){
            return 0;
        }
        
        // At kth iteration:
        //    dp[k % 2][i]: min remaining white tiles
        //                  when we cover s[0 .. i] with at most k carpets
        vector<vector<int>> dp(2, vector<int>(N, INF));
        
        dp[0][0] = (int)(s[0] == '1');
        for(int i = 1; i < N; ++i){
            dp[0][i] = dp[0][i - 1] + (int)(s[i] == '1');
        }
        
        for(int k = 1; k <= numCarpets; ++k){
            for(int i = 0; i < N; ++i){
                if(i <= carpetLen - 1){
                    dp[k % 2][i] = 0;
                }else{
                    dp[k % 2][i] = min(dp[k % 2][i - 1] + (int)(s[i] == '1'), dp[(k - 1) % 2][i - carpetLen]);
                }
            }
        }
        
        return dp[numCarpets % 2][N - 1];
    }
};