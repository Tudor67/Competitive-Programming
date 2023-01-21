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
        //         maximizing prefix sum + suffix sum is the same as
        //         minimizing the sum between prefix and suffix
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int minSum = 0;
        for(int num: nums){
            minSum = min(minSum + num, num);
            if(totalSum != minSum){
                res = max(res, totalSum - minSum);
            }
        }

        return res;
    }
};