class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int L = target / MIN_NUM;
        
        // At ith iteration:
        //    dp[i % 2][target]: number of possible combinations (of size i) that add up to target
        vector<vector<int>> dp(2, vector<int>(target + 1));
        for(int num: nums){
            if(num <= target){
                dp[1][num] = 1;
            }
        }
        
        int res = dp[1][target];
        for(int i = 2; i <= L; ++i){
            for(int sum = 0; sum <= target; ++sum){
                dp[i % 2][sum] = 0;
            }
            for(int num: nums){
                for(int sum = num; sum <= target; ++sum){
                    if(dp[i % 2][sum] <= INT_MAX - dp[(i - 1) % 2][sum - num]){
                        dp[i % 2][sum] += dp[(i - 1) % 2][sum - num];
                    }
                }
            }
            res += dp[i % 2][target];
        }
        
        return res;
    }
};