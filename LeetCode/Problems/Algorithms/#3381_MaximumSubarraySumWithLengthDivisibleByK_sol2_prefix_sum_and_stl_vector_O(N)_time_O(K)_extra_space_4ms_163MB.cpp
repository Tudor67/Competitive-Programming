class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long INF = 1e18;

        long long maxSum = -INF;
        vector<long long> minPrefSum(k, INF);
        minPrefSum[0] = 0;

        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            int rem = (i + 1) % k;
            maxSum = max(maxSum, prefSum - minPrefSum[rem]);
            minPrefSum[rem] = min(minPrefSum[rem], prefSum);
        }

        return maxSum;
    }
};