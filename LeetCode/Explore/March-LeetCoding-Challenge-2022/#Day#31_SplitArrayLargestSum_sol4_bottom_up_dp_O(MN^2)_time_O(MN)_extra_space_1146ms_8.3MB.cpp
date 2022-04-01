class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        const int INF = 1e9 + 5;
        
        vector<int> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        // dp[i][k]: min largest sum to split nums[0 .. i]
        //           into k non-empty continuous subarrays
        vector<vector<int>> dp(N, vector<int>(m + 1, INF));
        
        for(int i = 0; i < N; ++i){
            dp[i][1] = prefSum[i];
        }
        
        for(int k = 2; k <= m; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = i; j < N; ++j){
                    dp[j][k] = min(dp[j][k], max(dp[i][k - 1], prefSum[j] - prefSum[i]));
                }
            }
        }
        
        return dp[N - 1][m];
    }
};