class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        int leftMin = nums[0];
        for(int j = 1; j < N - 1; ++j){
            leftMin = min(leftMin, nums[j - 1]);
            for(int k = j + 1; k < N; ++k){
                if(leftMin < nums[k] && nums[k] < nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};