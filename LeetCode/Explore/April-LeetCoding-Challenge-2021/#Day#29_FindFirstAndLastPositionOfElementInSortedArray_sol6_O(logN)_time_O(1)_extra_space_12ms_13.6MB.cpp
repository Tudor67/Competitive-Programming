class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();
        if(nums.empty()){
            return {-1, -1};
        }
        
        // binary search target (firstPos)
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(target <= nums[mid]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        int firstPos = -1;
        if(nums[r] == target){
            firstPos = r;
        }
        
        // binary search target (lastPos)
        l = 0;
        r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(nums[mid] <= target){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        int lastPos = -1;
        if(nums[r] == target){
            lastPos = r;
        }
        
        return {firstPos, lastPos};
    }
};