class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        const int N = nums.size();

        // dp[0][i]: max score for a subsequence of nums[0 .. i] when the last num is even
        // dp[0][i]: max score for a subsequence of nums[0 .. i] when the last num is odd
        // we always take nums[0]
        vector<vector<long long>> dp(2, vector<long long>(N));
        dp[nums[0] % 2][0] = nums[0];
        dp[1 - (nums[0] % 2)][0] = nums[0] - x;

        for(int i = 1; i < N; ++i){
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1];

            int parity = nums[i] % 2;
            dp[parity][i] = max(dp[parity][i - 1] + nums[i], dp[1 - parity][i - 1] + nums[i] - x);
        }

        return max(dp[0][N - 1], dp[1][N - 1]);
    }
};