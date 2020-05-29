class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        vector<vector<int>> dp(N, vector<int>(M, 0));
        
        dp[0][0] = (A[0] == B[0]);
        for(int i = 1; i < N; ++i){
            dp[i][0] = (A[i] == B[0]) || dp[i - 1][0];
        }
        
        for(int j = 1; j < M; ++j){
            dp[0][j] = (A[0] == B[j]) || dp[0][j - 1];
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < M; ++j){
                if(A[i] == B[j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[N - 1][M - 1];
    }
};