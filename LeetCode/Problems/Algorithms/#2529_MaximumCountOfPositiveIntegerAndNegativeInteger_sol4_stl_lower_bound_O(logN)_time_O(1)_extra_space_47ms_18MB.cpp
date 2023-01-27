class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const int N = nums.size();
        int pos = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int neg = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        return max(pos, neg);
    }
};