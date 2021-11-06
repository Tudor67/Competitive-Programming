class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        const int EVEN = 0;
        const int ODD = 1;
        
        // At step i:
        // dp[EVEN][i % 2]: max sum of a subsequence of nums[0 .. i]
        //                  such that the last taken num is on even position (after re-indexing)
        // dp[ODD][i % 2]: max sum of a subsequence of nums[0 .. i]
        //                 such that the last taken num is on odd position (after re-indexing)
        vector<vector<long long>> dp(2, vector<long long>(2));
        dp[EVEN][0] = 0;
        dp[ODD][0] = nums[0];
        for(int i = 1; i < N; ++i){
            dp[EVEN][i % 2] = max(dp[EVEN][(i - 1) % 2], dp[ODD][(i - 1) % 2] - nums[i]);
            dp[ODD][i % 2] = max(dp[ODD][(i - 1) % 2], dp[EVEN][(i - 1) % 2] + nums[i]);
        }
        
        return dp[ODD][(N - 1) % 2];
    }
};