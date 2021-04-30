class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = -1;
        int lastPos = -1;
        pair<vector<int>::iterator, vector<int>::iterator> bounds = equal_range(nums.begin(), nums.end(), target);
        if(bounds.first != nums.end() && *bounds.first == target){
            firstPos = bounds.first - nums.begin();
            lastPos = bounds.second - nums.begin() - 1;
        }
        return {firstPos, lastPos};
    }
};