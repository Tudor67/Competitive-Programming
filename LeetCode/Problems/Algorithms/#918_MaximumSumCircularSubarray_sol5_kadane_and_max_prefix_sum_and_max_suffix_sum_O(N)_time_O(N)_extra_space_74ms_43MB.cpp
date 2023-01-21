class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int N = nums.size();

        int res = nums[0];

        // Case 1: find max sum subarray of nums[0 .. N - 1]
        int maxSum = 0;
        for(int num: nums){
            maxSum = max(maxSum + num, num);
            res = max(res, maxSum);
        }
        
        // Case 2: find max sum subarray around nums[N - 1]
        //         (i.e. contains a prefix and a suffix of nums,
        //               such that prefix and suffix do not intersect)
        int prefSum = 0;
        vector<int> prefSumMax(N);
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            if(i == 0){
                prefSumMax[i] = prefSum;
            }else{
                prefSumMax[i] = max(prefSumMax[i - 1], prefSum);
            }
        }

        int suffSum = 0;
        vector<int> suffSumMax(N);
        for(int i = N - 1; i >= 0; --i){
            suffSum += nums[i];
            if(i == N - 1){
                suffSumMax[i] = suffSum;
            }else{
                suffSumMax[i] = max(suffSum, suffSumMax[i + 1]);
            }
        }

        for(int i = 1; i < N; ++i){
            res = max(res, prefSumMax[i - 1] + suffSumMax[i]);
        }

        return res;
    }
};