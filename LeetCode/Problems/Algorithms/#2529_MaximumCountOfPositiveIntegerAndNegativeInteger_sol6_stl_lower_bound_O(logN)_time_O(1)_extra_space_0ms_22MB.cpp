class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int positive = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        return max(negative, positive);
    }
};