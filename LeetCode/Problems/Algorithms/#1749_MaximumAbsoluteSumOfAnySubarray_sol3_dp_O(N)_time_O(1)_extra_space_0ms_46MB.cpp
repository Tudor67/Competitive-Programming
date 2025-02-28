class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int N = nums.size();

        int maxAbsSum = 0;
        int maxSum = 0; // maxSum of a subarray ending at index i
        int minSum = 0; // minSum of a subarray ending at index i
        for(int i = 0; i < N; ++i){
            maxSum = max(maxSum + nums[i], nums[i]);
            minSum = min(minSum + nums[i], nums[i]);
            maxAbsSum = max(maxAbsSum, max(maxSum, -minSum));
        }

        return maxAbsSum;
    }
};