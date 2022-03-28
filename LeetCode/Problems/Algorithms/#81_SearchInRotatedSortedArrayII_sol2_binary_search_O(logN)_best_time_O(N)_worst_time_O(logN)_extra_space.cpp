class Solution {
private:
    bool binarySearch(vector<int>& nums, int l, int r, int target){
        if(l == r){
            return (nums[r] == target);
        }
        
        int mid = (l + r) / 2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[l] == nums[mid] && nums[mid] == nums[r]){
            return binarySearch(nums, l, r - 1, target);
        }
        if(nums[l] <= nums[mid]){
            if(nums[l] <= target && target <= nums[mid]){
                return binarySearch(nums, l, mid, target);
            }else{
                return binarySearch(nums, mid + 1, r, target);
            }
        }
        if(nums[mid] <= nums[r]){
            if(nums[mid + 1] <= target && target <= nums[r]){
                return binarySearch(nums, mid + 1, r, target);
            }
        }
        return binarySearch(nums, l, mid, target);
    }
    
public:
    bool search(vector<int>& nums, int target) {
        const int N = nums.size();
        return binarySearch(nums, 0, N - 1, target);
    }
};