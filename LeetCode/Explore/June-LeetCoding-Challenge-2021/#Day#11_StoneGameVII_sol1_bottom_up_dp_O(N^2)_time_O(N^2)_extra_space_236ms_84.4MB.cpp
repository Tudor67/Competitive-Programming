class Solution {
private:
    int rangeSum(vector<int>& prefixSum, int start, int end){
        if(start == 0){
            return prefixSum[end];
        }
        return prefixSum[end] - prefixSum[start - 1];
    }
    
public:
    int stoneGameVII(vector<int>& stones) {
        const int N = stones.size();
        
        vector<int> prefixSum(N);
        prefixSum[0] = stones[0];
        for(int i = 1; i < N; ++i){
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int len = 2; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                dp[i][j] = max(rangeSum(prefixSum, i + 1, j) - dp[i + 1][j],
                               rangeSum(prefixSum, i, j - 1) - dp[i][j - 1]);
            }
        }
        
        return dp[0][N - 1];
    }
};