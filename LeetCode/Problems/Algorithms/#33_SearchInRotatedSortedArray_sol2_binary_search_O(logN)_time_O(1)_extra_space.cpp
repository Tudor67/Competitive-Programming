class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }else if(nums[mid + 1] <= nums[r]){
                if(nums[mid + 1] <= target && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
        }
        
        if(nums[r] == target){
            return r;
        }
        
        return -1;
    }
};