class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = -1;
        int last_pos = -1;
        
        if(!nums.empty()){
            // binary search first_pos of target
            int l = 0;
            int r = (int)nums.size() - 1;
            while(l != r){
                int mid = l + (r - l) / 2;
                if(target <= nums[mid]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            
            if(nums[r] == target){
                first_pos = r;
                // binary search last_pos of target
                l = first_pos;
                r = (int)nums.size() - 1;
                while(l != r){
                    int mid = l + (r - l) / 2;
                    if(target < nums[mid]){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }
                
                if(nums[r] == target){
                    last_pos = r;
                }else if(r - 1 >= 0 && nums[r - 1] == target){
                    last_pos = r - 1;
                }
            }
        }
        
        return {first_pos, last_pos};
    }
};