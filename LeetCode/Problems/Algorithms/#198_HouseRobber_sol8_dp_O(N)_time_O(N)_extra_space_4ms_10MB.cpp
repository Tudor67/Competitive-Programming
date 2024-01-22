class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();

        // dp[i]: max amount of money when we rob nums[0 .. i]
        vector<int> dp(N);
        dp[0] = nums[0];
        
        for(int i = 1; i < N; ++i){
            if(i >= 2){
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }else{
                dp[i] = max(dp[i - 1], nums[i]);
            }
        }

        return dp[N - 1];
    }
};