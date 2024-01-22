class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();

        // At ith iteration:
        //    dp[i % 3]: max amount of money when we rob nums[0 .. i]
        vector<int> dp(3);
        dp[0] = nums[0];

        for(int i = 1; i < N; ++i){
            if(i >= 2){
                dp[i % 3] = max(dp[(i - 1) % 3], dp[(i - 2) % 3] + nums[i]);
            }else{
                dp[i % 3] = max(dp[(i - 1) % 3], nums[i]);
            }
        }

        return dp[(N - 1) % 3];
    }
};