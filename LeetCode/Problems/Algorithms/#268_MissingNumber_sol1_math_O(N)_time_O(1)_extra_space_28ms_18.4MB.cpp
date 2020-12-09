class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        const int EXPECTED_SUM = N * (N + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int missingNumber = EXPECTED_SUM - sum;
        return missingNumber;
    }
};