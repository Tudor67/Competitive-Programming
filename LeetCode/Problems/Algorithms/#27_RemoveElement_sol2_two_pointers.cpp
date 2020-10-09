class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = (int)nums.size();
        int i = 0;
        while(i < len){
            if(nums[i] == val){
                nums[i] = nums[len - 1];
                len -= 1;
            }else{
                i += 1;
            }
        }
        return len;
    }
};