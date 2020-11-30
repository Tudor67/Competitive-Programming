class Solution {
private:
    bool isPossible(int subsetSum, int i, vector<vector<bool>>& memo, const vector<int>& NUMS){
        if(i < 0 || subsetSum < 0 || memo[subsetSum][i]){
            return false;
        }
        
        if(subsetSum == 0){
            return true;
        }
        
        memo[subsetSum][i] = true;
        return isPossible(subsetSum - NUMS[i], i - 1, memo, NUMS) || isPossible(subsetSum, i - 1, memo, NUMS);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int SUBSET_SUM = TOTAL_SUM / 2;
        
        if(TOTAL_SUM % 2 == 1){
            return false;
        }
        
        vector<vector<bool>> memo(SUBSET_SUM + 1, vector<bool>(N, false));
        return isPossible(SUBSET_SUM, N - 1, memo, nums);
    }
};