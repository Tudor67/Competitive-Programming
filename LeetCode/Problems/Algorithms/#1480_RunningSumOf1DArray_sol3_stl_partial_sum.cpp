class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int N = nums.size();
        vector<int> prefSum(N);
        partial_sum(nums.begin(), nums.end(), prefSum.begin());
        return prefSum;
    }
};