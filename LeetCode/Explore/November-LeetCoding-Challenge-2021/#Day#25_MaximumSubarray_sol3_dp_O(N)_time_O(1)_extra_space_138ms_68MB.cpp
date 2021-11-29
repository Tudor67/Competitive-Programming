class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[i]: largest sum of a contiguous subarray ending at i
        vector<int> dp(2);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < N; ++i){
            dp[i % 2] = max(dp[(i - 1) % 2] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i % 2]);
        }
        
        return maxSum;
    }
};