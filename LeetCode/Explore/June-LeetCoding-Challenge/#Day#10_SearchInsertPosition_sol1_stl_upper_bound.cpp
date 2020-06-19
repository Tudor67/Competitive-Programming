class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(!nums.empty() && pos > 0 && nums[pos - 1] == target){
            pos = pos - 1;
        }
        return pos;
    }
};