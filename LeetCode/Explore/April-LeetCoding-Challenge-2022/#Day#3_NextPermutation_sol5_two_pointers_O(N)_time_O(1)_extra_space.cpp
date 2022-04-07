class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        
        bool updated = false;
        for(int i = N - 2; !updated && i >= 0; --i){
            if(nums[i] < nums[i + 1]){
                int j = N - 1;
                while(nums[i] >= nums[j]){
                    --j;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                updated = true;
            }
        }
        
        if(!updated){
            reverse(nums.begin(), nums.end());
        }
    }
};