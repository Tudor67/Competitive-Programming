class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int SHIFT = TOTAL_SUM + MAX_NUM;
        
        // At ith iteration:
        //    dp[i % 2][s + SHIFT]: number of different expressions with sum s
        //                          when we use nums[0 .. i]
        vector<vector<int>> dp(2, vector<int>(2 * SHIFT + 1));
        dp[0][ nums[0] + SHIFT] += 1;
        dp[0][-nums[0] + SHIFT] += 1;
        for(int i = 1; i < N; ++i){
            fill(dp[i % 2].begin(), dp[i % 2].end(), 0);
            for(int s = -TOTAL_SUM; s <= TOTAL_SUM; ++s){
                dp[i % 2][s - nums[i] + SHIFT] += dp[(i - 1) % 2][s + SHIFT];
                dp[i % 2][s + nums[i] + SHIFT] += dp[(i - 1) % 2][s + SHIFT];
            }
        }
        
        return dp[(N - 1) % 2][target + SHIFT];
    }
};