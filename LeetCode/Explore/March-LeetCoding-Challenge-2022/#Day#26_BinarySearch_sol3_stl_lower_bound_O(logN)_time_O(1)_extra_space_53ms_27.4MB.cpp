class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(idx < N && nums[idx] == target){
            return idx;
        }
        
        return -1;
    }
};