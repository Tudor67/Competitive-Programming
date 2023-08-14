class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();

        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                l = mid;
                r = mid;
            }else if(nums[mid] < target){
                if(target <= nums[r] || nums[mid] > nums[r]){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }else if(target < nums[mid]){
                if(nums[l] <= target || nums[l] > nums[mid]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
        }

        if(nums[r] == target){
            return r;
        }

        return -1;
    }
};