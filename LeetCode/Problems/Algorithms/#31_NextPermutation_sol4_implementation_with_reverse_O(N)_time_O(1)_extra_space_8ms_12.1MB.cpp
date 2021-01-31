class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        
        bool updated = false;
        for(int i = N - 1; !updated && i >= 1; --i){
            if(nums[i - 1] < nums[i]){
                int j = i;
                while(j < N && nums[i - 1] < nums[j]){
                    j += 1;
                }
                j -= 1;
                swap(nums[i - 1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                updated = true;
            }
        }
        
        if(!updated){
            reverse(nums.begin(), nums.end());
        }
    }
};