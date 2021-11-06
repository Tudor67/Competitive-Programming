class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        const int EVEN = 0;
        const int ODD = 1;
        
        // dp[EVEN][i]: max sum of a subsequence of nums[0 .. i]
        //              such that the last taken num is on even position (after re-indexing)
        // dp[ODD][i]: max sum of a subsequence of nums[0 .. i]
        //             such that the last taken num is on odd position (after re-indexing)
        vector<vector<long long>> dp(2, vector<long long>(N));
        dp[EVEN][0] = 0;
        dp[ODD][0] = nums[0];
        for(int i = 1; i < N; ++i){
            dp[EVEN][i] = max(dp[EVEN][i - 1], dp[ODD][i - 1] - nums[i]);
            dp[ODD][i] = max(dp[ODD][i - 1], dp[EVEN][i - 1] + nums[i]);
        }
        
        return dp[ODD][N - 1];
    }
};