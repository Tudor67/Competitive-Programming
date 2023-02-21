class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N / 2;
        while(l != r){
            int mid = (l + r) / 2;
            if(nums[2 * mid] == nums[2 * mid + 1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return nums[2 * r];
    }
};