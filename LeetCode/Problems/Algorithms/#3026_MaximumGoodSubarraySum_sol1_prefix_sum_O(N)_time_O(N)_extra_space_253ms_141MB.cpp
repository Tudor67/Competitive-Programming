class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long INF = 1e16;

        long long res = -INF;
        long long prefSum = 0;
        unordered_map<int, long long> minPrefSum;

        for(int num: nums){
            if(minPrefSum.count(num)){
                minPrefSum[num] = min(minPrefSum[num], prefSum);
            }else{
                minPrefSum[num] = prefSum;
            }

            prefSum += num;

            if(minPrefSum.count(num - k)){
                res = max(res, prefSum - minPrefSum[num - k]);
            }
            if(minPrefSum.count(num + k)){
                res = max(res, prefSum - minPrefSum[num + k]);
            }
        }

        if(res == -INF){
            res = 0;
        }

        return res;
    }
};