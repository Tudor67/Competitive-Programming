class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        int size = 0;
        for(int i = 0; i < N; ++i){
            if(nums[i] != 0){
                size += 1;
                nums[size - 1] = nums[i];
            }
            if(size - 1 != i){
                nums[i] = 0;
            }
        }
        
        return nums;
    }
};