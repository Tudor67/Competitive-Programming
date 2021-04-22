class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[l][t]: number of possible combinations of len `l` that add up to target `t`
        vector<vector<int>> dp(target + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for(int len = 1; len <= target; ++len){
            for(int num: nums){
                for(int j = num; j <= target; ++j){
                    if(dp[len][j] <= INT_MAX - dp[len - 1][j - num]){
                        dp[len][j] += dp[len - 1][j - num];
                    }
                }
            }
        }
        
        int answer = 0;
        for(int len = 1; len <= target; ++len){
            answer += dp[len][target];
        }
        
        return answer;
    }
};