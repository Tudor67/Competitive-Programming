class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();
        
        int i = 0;
        for(int j = 0; j < N; ++j){
            if(nums[j] % 2 == 0){
                swap(nums[i], nums[j]);
                i += 1;
            }
        }
        
        return nums;
    }
};