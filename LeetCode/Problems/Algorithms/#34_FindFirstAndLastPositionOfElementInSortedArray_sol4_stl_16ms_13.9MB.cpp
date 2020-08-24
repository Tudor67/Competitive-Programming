class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = -1;
        int last_pos = -1;
        
        if(!nums.empty()){
            vector<int>::iterator it1 = lower_bound(nums.begin(), nums.end(), target);
            vector<int>::iterator it2 = upper_bound(nums.begin(), nums.end(), target);
            if(it1 != nums.end() && *it1 == target){
                first_pos = it1 - nums.begin();
                last_pos = it2 - nums.begin() - 1;
            }
        }
        
        return {first_pos, last_pos};
    }
};