class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();

        long long maxSum = LLONG_MIN;
        unordered_map<int, long long> minPrefSum;
        minPrefSum[0] = 0;

        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            int rem = (i + 1) % k;
            if(minPrefSum.count(rem)){
                maxSum = max(maxSum, prefSum - minPrefSum[rem]);
                minPrefSum[rem] = min(minPrefSum[rem], prefSum);
            }else{
                minPrefSum[rem] = prefSum;
            }
        }

        return maxSum;
    }
};