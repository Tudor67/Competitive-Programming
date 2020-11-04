class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();
        nth_element(nums.begin(), nums.begin() + N - k, nums.end());
        return nums[N - k];
    }
};