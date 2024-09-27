class Solution {
private:
    int maxOperations(int targetSum, int i, int j, vector<int>& nums, vector<vector<int>>& memo){
        if(i >= j){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int maxOps = 0;
        if(targetSum == nums[i] + nums[i + 1]){
            maxOps = max(maxOps, 1 + maxOperations(targetSum, i + 2, j, nums, memo));
        }
        if(targetSum == nums[j - 1] + nums[j]){
            maxOps = max(maxOps, 1 + maxOperations(targetSum, i, j - 2, nums, memo));
        }
        if(targetSum == nums[i] + nums[j]){
            maxOps = max(maxOps, 1 + maxOperations(targetSum, i + 1, j - 1, nums, memo));
        }

        memo[i][j] = maxOps;
        return maxOps;
    }

public:
    int maxOperations(vector<int>& nums) {
        const int N = nums.size();

        int maxOps = 0;
        set<int> targetSums = {nums[0] + nums[1], nums[N - 2] + nums[N - 1], nums[0] + nums[N - 1]};
        vector<vector<int>> memo(N, vector<int>(N));
        for(int targetSum: targetSums){
            for(int i = 0; i < N; ++i){
                for(int j = i; j < N; ++j){
                    memo[i][j] = -1;
                }
            }
            maxOps = max(maxOps, maxOperations(targetSum, 0, N - 1, nums, memo));
        }

        return maxOps;
    }
};