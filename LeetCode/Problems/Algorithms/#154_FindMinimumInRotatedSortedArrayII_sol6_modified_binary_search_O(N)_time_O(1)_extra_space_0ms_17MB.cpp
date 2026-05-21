class Solution {
public:
    int findMin(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[mid] == nums[r]){
                r = r - 1;
            }else if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return nums[r];
    }
};