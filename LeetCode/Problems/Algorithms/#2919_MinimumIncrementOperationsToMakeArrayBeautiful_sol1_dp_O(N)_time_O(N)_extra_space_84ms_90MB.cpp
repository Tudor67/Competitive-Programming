class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long INF = 1e16;
        
        // dp[i]: min cost for nums[0 .. i]
        //        when we make all subarrays (with a size >= 3) beautiful
        //                     and (nums[i] >= k)
        vector<long long> dp(N, INF);
        
        for(int i = 0; i < N; ++i){
            long long takeCost = max(0, k - nums[i]);
            
            if(i < 3){
                dp[i] = takeCost;
            }
            
            for(int j = max(0, i - 3); j < i; ++j){
                dp[i] = min(dp[i], dp[j] + takeCost);
            }
        }
        
        return *min_element(dp.end() - 3, dp.end());
    }
};