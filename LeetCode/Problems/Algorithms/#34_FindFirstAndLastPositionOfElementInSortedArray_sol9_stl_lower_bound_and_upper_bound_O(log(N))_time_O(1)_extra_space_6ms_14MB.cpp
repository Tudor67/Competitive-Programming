class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();

        int firstPos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int lastPos = upper_bound(nums.begin() + firstPos, nums.end(), target) - nums.begin() - 1;

        if(firstPos < N && nums[firstPos] == target){
            return {firstPos, lastPos};
        }

        return {-1, -1};
    }
};