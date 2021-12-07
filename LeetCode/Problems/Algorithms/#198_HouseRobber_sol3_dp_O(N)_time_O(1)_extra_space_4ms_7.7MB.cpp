class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[0][i]: max profit for nums[0 .. i] when we don't take nums[i]
        // dp[1][i]: max profit for nums[0 .. i] when we take nums[i]
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for(int i = 1; i < N; ++i){
            dp[0][i % 2] = max(dp[0][(i - 1) % 2], dp[1][(i - 1) % 2]);
            dp[1][i % 2] = dp[0][(i - 1) % 2] + nums[i];
        }
        
        return max(dp[0][(N - 1) % 2], dp[1][(N - 1) % 2]);
    }
};