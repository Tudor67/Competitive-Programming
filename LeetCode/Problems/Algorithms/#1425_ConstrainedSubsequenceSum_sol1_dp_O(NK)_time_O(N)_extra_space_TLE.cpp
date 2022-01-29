class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        
        // dp[i]: max sum of a valid subsequence ending at position i
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            dp[i] = nums[i];
            for(int j = i - 1; j >= max(0, i - k); --j){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};