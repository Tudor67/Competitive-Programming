class Solution {
public:
    int minStartValue(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[i]: minimum start value to solve nums[i .. N - 1]
        vector<int> dp(N);
        dp[N - 1] = max(1, -nums[N - 1] + 1);
        for(int i = N - 2; i >= 0; --i){
            dp[i] = max(1, -nums[i] + dp[i + 1]);
        }
        
        return dp[0];
    }
};