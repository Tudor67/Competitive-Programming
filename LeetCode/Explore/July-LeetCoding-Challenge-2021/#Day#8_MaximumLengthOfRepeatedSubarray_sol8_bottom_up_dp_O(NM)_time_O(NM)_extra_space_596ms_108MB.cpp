class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        
        // dp[i][j]: max length of subarray that appears in both suffixes A[0..i] and B[0..j]
        vector<vector<int>> dp(N, vector<int>(M));
        int maxLength = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(A[i] == B[j]){
                    if(i > 0 && j > 0){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }else{
                        dp[i][j] = 1;
                    }
                }else{
                    dp[i][j] = 0;
                }
                maxLength = max(dp[i][j], maxLength);
            }
        }
        
        return maxLength;
    }
};