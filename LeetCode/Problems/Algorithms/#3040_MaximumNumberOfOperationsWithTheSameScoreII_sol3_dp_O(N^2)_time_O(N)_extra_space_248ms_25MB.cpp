class Solution {
private:
    int maxOperations(int targetSum, vector<int>& nums){
        const int N = nums.size();

        // At (len - 1)th iteration:
        //    dp[len % 3][i]: max ops for nums[i .. i + len - 1]
        //                    when the target sum is targetSum
        vector<vector<int>> dp(3, vector<int>(N + 1));
        for(int len = 2; len <= N; ++len){
            fill(dp[len % 3].begin(), dp[len % 3].end(), 0);
            for(int i = 0; i + len - 1 < N; ++i){
                if(nums[i] + nums[i + 1] == targetSum){
                    dp[len % 3][i] = max(dp[len % 3][i], 1 + dp[(len - 2) % 3][i + 2]);
                }
                if(nums[i + len - 2] + nums[i + len - 1] == targetSum){
                    dp[len % 3][i] = max(dp[len % 3][i], 1 + dp[(len - 2) % 3][i]);
                }
                if(nums[i] + nums[i + len - 1] == targetSum){
                    dp[len % 3][i] = max(dp[len % 3][i], 1 + dp[(len - 2) % 3][i + 1]);
                }
            }
        }
        
        return dp[N % 3][0];
    }

public:
    int maxOperations(vector<int>& nums) {
        const int N = nums.size();

        int maxOps = 0;
        set<int> targetSums = {nums[0] + nums[1], nums[N - 2] + nums[N - 1], nums[0] + nums[N - 1]};
        for(int targetSum: targetSums){
            maxOps = max(maxOps, maxOperations(targetSum, nums));
        }

        return maxOps;
    }
};