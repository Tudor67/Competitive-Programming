class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        // dp[i]: number of arithmetic slices ending at index i
        vector<int> dp(N);
        int res = 0;
        for(int i = 2; i < N; ++i){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                dp[i] = dp[i - 1] + 1;
            }
            res += dp[i];
        }
        
        return res;
    }
};