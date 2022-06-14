class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        
        int j = N - 1;
        for(int i = 0; i < j; ++i){
            while(i < j && nums[i] + nums[j] > target){
                --j;
            }
            if(i < j && nums[i] + nums[j] == target){
                return {i + 1, j + 1};
            }
        }
        
        return {-1, -1};
    }
};