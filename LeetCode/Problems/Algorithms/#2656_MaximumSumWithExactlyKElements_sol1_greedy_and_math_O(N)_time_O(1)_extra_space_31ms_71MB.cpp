class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        return MAX_NUM * k + (k - 1) * k / 2;
    }
};