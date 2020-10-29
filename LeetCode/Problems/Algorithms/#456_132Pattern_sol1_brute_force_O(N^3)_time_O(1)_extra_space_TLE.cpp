class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N - 2; ++i){
            for(int j = i + 1; j < N - 1; ++j){
                for(int k = j + 1; k < N; ++k){
                    if(nums[i] < nums[k] && nums[k] < nums[j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};