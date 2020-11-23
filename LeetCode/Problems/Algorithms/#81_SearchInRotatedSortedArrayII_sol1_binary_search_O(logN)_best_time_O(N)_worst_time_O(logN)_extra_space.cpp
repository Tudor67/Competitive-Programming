class Solution {
private:
    bool search(vector<int>& nums, int l, int r, int target){
        // Case 0: invalid range
        if(l > r){
            return false;
        }
        // Case 1: range with one number
        if(l == r){
            return (nums[r] == target);
        }
        
        // Case 2: range with more than one number
        int mid = (l + r) / 2;
        // Case 2.1: nums[l] == nums[mid]
        if(nums[l] == nums[mid]){
            return search(nums, l, mid, target) || search(nums, mid + 1, r, target);
        }
        // Case 2.2: nums[l] > nums[mid]
        if(nums[l] > nums[mid]){
            if(target >= nums[l] || target <= nums[mid]){
                return search(nums, l, mid, target);
            }else{
                return search(nums, mid + 1, r, target);
            }
        }
        // Case 2.3: nums[l] < nums[mid]
        if(nums[l] <= target && target <= nums[mid]){
            return search(nums, l, mid, target);
        }else{
            return search(nums, mid + 1, r, target);
        }
    }
    
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, (int)nums.size() - 1, target);
    }
};