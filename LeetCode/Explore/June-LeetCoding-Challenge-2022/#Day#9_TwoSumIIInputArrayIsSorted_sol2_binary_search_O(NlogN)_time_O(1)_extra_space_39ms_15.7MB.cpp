class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        
        for(int i = 0; i + 1 < N; ++i){
            int j = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin();
            if(j < N && nums[i] + nums[j] == target){
                return {i + 1, j + 1};
            }
        }
        
        return {-1, -1};
    }
};