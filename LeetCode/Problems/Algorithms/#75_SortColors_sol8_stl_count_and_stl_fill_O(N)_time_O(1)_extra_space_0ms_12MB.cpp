class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = count(nums.begin(), nums.end(), 0);
        int ones = count(nums.begin(), nums.end(), 1);

        fill(nums.begin(), nums.begin() + zeros, 0);
        fill(nums.begin() + zeros, nums.begin() + zeros + ones, 1);
        fill(nums.begin() + zeros + ones, nums.end(), 2);
    }
};