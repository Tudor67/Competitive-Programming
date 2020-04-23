class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] <= 0){
                nums[i] = nums.size() + 1;
            }
        }
        
        int pos;
        for(int i = 0; i < (int)nums.size(); ++i){
            pos = abs(nums[i]) - 1;
            if(pos < nums.size() && nums[pos] > 0){
                nums[pos] = -nums[pos];
            }
        }
        
        int ans = nums.size() + 1;
        for(int i = 0; i < (int)nums.size(); ++i){
            if(nums[i] > 0){
                ans = i + 1;
                break;
            }
        }
        
        return ans;
    }
};