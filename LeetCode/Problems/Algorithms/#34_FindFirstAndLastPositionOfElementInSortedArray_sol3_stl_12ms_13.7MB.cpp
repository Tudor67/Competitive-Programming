class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = -1;
        int last_pos = -1;
        
        if(!nums.empty()){
            vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
            if(it != nums.end() && *it == target){
                first_pos = it - nums.begin();
                last_pos = first_pos - 1 + upper_bound(it, nums.end(), target) - it;
            }
        }
        
        return {first_pos, last_pos};
    }
};