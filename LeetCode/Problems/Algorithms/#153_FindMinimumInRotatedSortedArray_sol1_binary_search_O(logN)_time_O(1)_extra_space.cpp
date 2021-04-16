class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[l] < nums[mid]){
                if(nums[mid] < nums[r]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }else{
                if(nums[mid] < nums[r]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return nums[r];
    }
};