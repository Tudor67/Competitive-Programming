class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        const int N = nums.size();
        const long long INF = 1e15;

        // prefSum[i] = nums[0] + nums[1] + ... + nums[i]
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        // maxLen[i]: max length of a non-decreasing array that can be made from nums[0 .. i]
        // minSum[i]: min sum of the group that includes nums[i]
        vector<int> maxLen(N);
        vector<long long> minSum(N, INF);
        maxLen[0] = 1;
        minSum[0] = nums[0];

        for(int i = 0; i < N; ++i){
            if(i >= 1 && maxLen[i - 1] >= maxLen[i]){
                maxLen[i] = maxLen[i - 1];
                minSum[i] = min(minSum[i], minSum[i - 1] + nums[i]);
            }

            long long j = lower_bound(prefSum.begin() + i, prefSum.end(), prefSum[i] + minSum[i])
                          - prefSum.begin();
            if(j < N){
                maxLen[j] = max(maxLen[j], maxLen[i] + 1);
                minSum[j] = min(minSum[j], prefSum[j] - prefSum[i]);
            }
        }

        return maxLen[N - 1];
    }
};