class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int L = target / MIN_NUM;
        
        // dp[i][target]: number of possible combinations (of size i) that add up to target
        vector<vector<int>> dp(L + 1, vector<int>(target + 1));
        for(int num: nums){
            if(num <= target){
                dp[1][num] = 1;
            }
        }
        
        for(int i = 2; i <= L; ++i){
            for(int num: nums){
                for(int sum = num; sum <= target; ++sum){
                    if(dp[i][sum] <= INT_MAX - dp[i - 1][sum - num]){
                        dp[i][sum] += dp[i - 1][sum - num];
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= L; ++i){
            res += dp[i][target];
        }
        
        return res;
    }
};