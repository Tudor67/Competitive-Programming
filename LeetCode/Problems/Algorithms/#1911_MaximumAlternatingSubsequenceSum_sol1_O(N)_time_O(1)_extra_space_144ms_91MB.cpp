class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();
        long long maxSum = nums[0];
        for(int i = 1; i < N; ++i){
            maxSum += max(0, nums[i] - nums[i - 1]);
        }
        return maxSum;
    }
};