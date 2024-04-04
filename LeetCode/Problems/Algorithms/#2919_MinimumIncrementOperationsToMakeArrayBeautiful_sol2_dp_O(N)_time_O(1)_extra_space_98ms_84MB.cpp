class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long INF = 1e16;
        
        // At ith iteration:
        // dp[i % 3]: min cost for nums[0 .. i]
        //            when we make all subarrays (with a size >= 3) beautiful
        //                         and (nums[i] >= k)
        vector<long long> dp(3, INF);
        
        for(int i = 0; i < N; ++i){
            long long takeCost = max(0, k - nums[i]);
            if(i < 3){
                dp[i % 3] = takeCost;
            }else{
                dp[i % 3] = takeCost + *min_element(dp.begin(), dp.end());
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};