class Solution {
private:
    inline int valAt(vector<vector<int>>& dp, int i, int j){
        const int N = dp.size();
        const int M = dp[0].size();
        if(0 <= i && i < N && 0 <= j && j < M){
            return dp[i][j];
        }
        return 0;
    }
    
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        const int M = B.size();
        
        int answer = 0;
        // dp[i][j]: max length of subarrays suffixes A[..i] and B[..j]
        vector<vector<int>> dp(N, vector<int>(M, 0));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(A[i] == B[j]){
                    dp[i][j] = 1 + valAt(dp, i - 1, j - 1);
                }
                answer = max(dp[i][j], answer);
            }
        }
        
        return answer;
    }
};