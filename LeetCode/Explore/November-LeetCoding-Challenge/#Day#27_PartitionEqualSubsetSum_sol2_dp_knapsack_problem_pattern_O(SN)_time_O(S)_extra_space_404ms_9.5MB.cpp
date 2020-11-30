class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int SUM = accumulate(nums.begin(), nums.end(), 0);
        
        // Case 1: we cannot partition the array if the SUM is odd
        if(SUM % 2 == 1){
            return false;
        }
        
        // Case 2: we try to create a partition such that the sum of elements is equal to SUM / 2
        //         we can do this using classical dp (knapsack problem for SUM / 2)
        //         if this is possible then we can partition the array into two subsets with equal sums
        vector<bool> isPossible(SUM / 2 + 1, false);
        isPossible[0] = true;
        for(int i = 0; !isPossible[SUM / 2] && i < nums.size(); ++i){
            for(int j = SUM / 2; j >= nums[i]; --j){
                isPossible[j] = isPossible[j] || isPossible[j - nums[i]];
            }
        }
        
        return isPossible[SUM / 2];
    }
};