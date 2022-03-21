class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[i]: number of arithmetic slices ending at index i
        vector<int> dp(2);
        int res = 0;
        for(int i = 2; i < N; ++i){
            dp[i % 2] = 0;
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                dp[i % 2] = dp[(i - 1) % 2] + 1;
            }
            res += dp[i % 2];
        }
        
        return res;
    }
};