class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        for(int j = 2; j < nums.size(); ++j){
            if(!(nums[i - 1] == nums[i] && nums[i] == nums[j])){
                nums[++i] = nums[j];
            }
        }
        return min((int)nums.size(), i + 1);
    }
};