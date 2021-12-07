class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 2){
            return *max_element(nums.begin(), nums.end());
        }
        
        // dp[i]: max profit for nums[0 .. i]
        vector<int> dp(N);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < N; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[N - 1];
    }
};