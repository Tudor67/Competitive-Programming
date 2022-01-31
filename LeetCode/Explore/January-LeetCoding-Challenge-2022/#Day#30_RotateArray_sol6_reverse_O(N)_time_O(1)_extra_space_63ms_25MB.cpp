class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = nums.size();
        k %= N;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};