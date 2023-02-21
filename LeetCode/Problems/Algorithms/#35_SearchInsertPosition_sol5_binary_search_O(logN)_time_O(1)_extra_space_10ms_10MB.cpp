class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int N = nums.size();

        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};