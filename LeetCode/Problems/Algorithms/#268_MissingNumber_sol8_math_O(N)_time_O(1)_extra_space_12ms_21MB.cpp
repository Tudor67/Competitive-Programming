class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        int currentSum = accumulate(nums.begin(), nums.end(), 0);
        int targetSum = N * (N + 1) / 2;
        return targetSum - currentSum;
    }
};