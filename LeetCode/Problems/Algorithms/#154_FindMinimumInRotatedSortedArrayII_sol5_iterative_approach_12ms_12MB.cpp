class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[l] < nums[r]){
                r = l;
            }else if(nums[mid] > nums[r]){
                l = mid + 1;
            }else if(nums[mid] < nums[r]){
                r = mid;
            }else{
                l += 1;
            }
        }
        return nums[r];
    }
};