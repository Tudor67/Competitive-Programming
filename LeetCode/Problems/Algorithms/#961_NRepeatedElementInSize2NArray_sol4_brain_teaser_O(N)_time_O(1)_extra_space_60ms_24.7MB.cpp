class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int N = nums.size() / 2;
        
        for(int i = 0; i < 2 * N; ++i){
            for(int j = i + 1; j < min(i + 4, 2 * N); ++j){
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        
        return -1;
    }
};