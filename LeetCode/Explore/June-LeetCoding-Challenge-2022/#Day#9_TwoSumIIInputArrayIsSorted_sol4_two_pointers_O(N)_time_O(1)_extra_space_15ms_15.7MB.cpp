class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(nums[i] + nums[j] < target){
                i += 1;
            }else if(nums[i] + nums[j] > target){
                j -= 1;
            }else{
                return {i + 1, j + 1};
            }
        }
        
        return {-1, -1};
    }
};