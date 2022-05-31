class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        const int TARGET_SUM = N * (N + 1) / 2;
        const int SUM = accumulate(nums.begin(), nums.end(), 0);
        return TARGET_SUM - SUM;
    }
};