class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        int duplicate = -1;
        int missing = -1;
        
        for(int num: nums){
            int idx = abs(num) - 1;
            if(nums[idx] < 0){
                duplicate = abs(num);
            }
            nums[idx] = -abs(nums[idx]);
        }
        
        for(int idx = 0; idx < N; ++idx){
            if(nums[idx] > 0){
                missing = idx + 1;
            }
        }
        
        for(int idx = 0; idx < N; ++idx){
            nums[idx] = abs(nums[idx]);
        }
        
        return {duplicate, missing};
    }
};