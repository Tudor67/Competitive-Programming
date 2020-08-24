class Solution {
private:
    int get_first_pos(const vector<int>& nums, const int& target){
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
        
        int pos = r;
        if(nums[pos] != target){
            pos = -1;
        }
        return pos;
    }
    
    int get_last_pos(const vector<int>& nums, const int& target){
        int l = 0;
        int r = (int)nums.size() - 1;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(target < nums[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        int pos = r;
        if(nums[pos] == target){
            return pos;
        }
        if(pos - 1 >= 0 && nums[pos - 1] == target){
            return pos - 1;
        }
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        return {get_first_pos(nums, target), get_last_pos(nums, target)};
    }
};