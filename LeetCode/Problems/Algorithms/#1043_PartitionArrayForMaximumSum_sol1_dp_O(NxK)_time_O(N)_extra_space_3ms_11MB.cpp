class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int N = arr.size();

        // dp[i]: largest sum for arr[i .. N - 1]
        //        when we partition arr[i .. N - 1] into subarrays of length at most k
        vector<int> dp(N + 1);
        for(int i = N - 1; i >= 0; --i){
            int currMax = arr[i];
            for(int j = i; j < min(N, i + k); ++j){
                currMax = max(currMax, arr[j]);
                dp[i] = max(dp[i], currMax * (j - i + 1) + dp[j + 1]);
            }
        }

        return dp[0];
    }
};