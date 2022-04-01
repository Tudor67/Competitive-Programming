class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        const int INF = 1e9 + 5;
        
        // dp[i][j][k]: min largest sum to split nums[i .. j]
        //              into k non-empty continuous subarrays
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(m + 1, INF)));
        
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += nums[j];
                dp[i][j][1] = sum;
            }
        }
        
        for(int k = 2; k <= m; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = i; j < N; ++j){
                    for(int splitPos = i; splitPos + 1 <= j; ++splitPos){
                        dp[i][j][k] = min(dp[i][j][k], max(dp[i][splitPos][k - 1], dp[splitPos + 1][j][1]));
                    }
                }
            }
        }
        
        return dp[0][N - 1][m];
    }
};