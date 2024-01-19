class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int N = nums.size();
        
        // dp[i]: max number of steps to reach index i
        vector<int> dp(N, -1);
        dp[0] = 0;
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = nums[i] - nums[j];
                if(-target <= diff && diff <= target && dp[j] >= 0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[N - 1];
    }
};