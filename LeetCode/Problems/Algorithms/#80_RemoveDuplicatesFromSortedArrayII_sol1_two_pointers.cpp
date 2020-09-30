class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for(int r = 2; r < nums.size(); ++r){
            if(nums[l - 1] != nums[l] || nums[l] != nums[r]){
                l += 1;
                nums[l] = nums[r];
            }
        }
        return min((int)nums.size(), l + 1);
    }
};