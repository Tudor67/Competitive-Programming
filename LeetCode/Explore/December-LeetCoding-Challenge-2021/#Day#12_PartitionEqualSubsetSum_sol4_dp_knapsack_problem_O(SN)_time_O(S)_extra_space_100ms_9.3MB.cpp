class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        
        if(TOTAL_SUM % 2 == 1){
            return false;
        }
        
        vector<bool> isPossible(TOTAL_SUM / 2 + 1, false);
        isPossible[0] = true;
        for(int i = 0; !isPossible[TOTAL_SUM / 2] && i < N; ++i){
            for(int j = TOTAL_SUM / 2; j >= nums[i]; --j){
                isPossible[j] = isPossible[j] || isPossible[j - nums[i]];
            }
        }
        
        return isPossible[TOTAL_SUM / 2];
    }
};