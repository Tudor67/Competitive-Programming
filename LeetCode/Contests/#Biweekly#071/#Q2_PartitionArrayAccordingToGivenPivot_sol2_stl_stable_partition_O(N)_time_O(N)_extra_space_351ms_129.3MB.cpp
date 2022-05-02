class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stable_partition(nums.begin(), nums.end(), [&](int num){ return (num == pivot); });
        stable_partition(nums.begin(), nums.end(), [&](int num){ return (num < pivot); });
        return nums;
    }
};