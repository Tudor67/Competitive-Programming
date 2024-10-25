class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long INF = 2e18;

        // dp[j][i]: max strength that can be obtained from
        //           selecting exactly j disjoint subarrays from nums[i ..]
        vector<vector<long long>> dp(k + 1, vector<long long>(N, -INF));
        long long maxSum = -INF;
        for(int i = N - 1; i >= 0; --i){
            maxSum = max((long long)nums[i], nums[i] + maxSum);
            dp[1][i] = maxSum;
        }

        for(int j = 2; j <= k; ++j){
            for(int i = N - 2; i >= 0; --i){
                long long kContrib = (j % 2 == 0 ? -j : j);
                dp[j][i] = kContrib * nums[i] + max(dp[j][i + 1], dp[j - 1][i + 1]);
            }
        }

        return *max_element(dp[k].begin(), dp[k].end());
    }
};