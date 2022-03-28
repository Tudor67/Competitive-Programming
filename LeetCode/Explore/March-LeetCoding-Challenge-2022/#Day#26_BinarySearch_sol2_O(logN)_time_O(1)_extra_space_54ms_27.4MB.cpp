class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        if(nums[r] == target){
            return r;
        }
        
        return -1;
    }
};