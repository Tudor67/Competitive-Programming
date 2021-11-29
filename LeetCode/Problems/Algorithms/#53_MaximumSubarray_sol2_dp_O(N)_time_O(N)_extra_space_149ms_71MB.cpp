class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[i]: largest sum of a contiguous subarray ending at i
        vector<int> dp(N);
        dp[0] = nums[0];
        for(int i = 1; i < N; ++i){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};