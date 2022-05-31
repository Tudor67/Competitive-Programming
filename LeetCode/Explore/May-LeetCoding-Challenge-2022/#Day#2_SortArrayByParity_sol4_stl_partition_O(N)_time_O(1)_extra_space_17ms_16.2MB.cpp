class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](int num){ return (num % 2 == 0); });
        return nums;
    }
};