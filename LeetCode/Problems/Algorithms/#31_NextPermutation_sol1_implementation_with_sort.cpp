class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        
        bool changed = false;
        for(int i = N - 2; !changed && i >= 0; --i){
            if(nums[i] < nums[i + 1]){
                int min_idx = i + 1;
                for(int j = i + 2; j < N; ++j){
                    if(nums[i] < nums[j] && nums[j] < nums[min_idx]){
                        min_idx = j;
                    }
                }
                
                swap(nums[i], nums[min_idx]);
                sort(nums.begin() + i + 1, nums.end());
                changed = true;
            }
        }
        
        if(!changed){
            reverse(nums.begin(), nums.end());
        }
    }
};