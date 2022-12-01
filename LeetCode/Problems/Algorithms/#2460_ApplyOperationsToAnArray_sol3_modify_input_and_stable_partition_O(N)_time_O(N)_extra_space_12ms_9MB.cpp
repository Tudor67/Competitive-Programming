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
        
        stable_partition(nums.begin(), nums.end(),
                         [](int num){
                             return (num != 0);
                         });
        
        return nums;
    }
};