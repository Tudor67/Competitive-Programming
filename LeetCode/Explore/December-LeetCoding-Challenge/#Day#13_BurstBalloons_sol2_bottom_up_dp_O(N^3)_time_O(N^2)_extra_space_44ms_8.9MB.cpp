class Solution {
public:
    int maxCoins(vector<int>& initialNums) {
        const int N = initialNums.size();
        
        // nums = [1] + initialNums + [1]
        vector<int> nums(N + 2, 1);
        copy(initialNums.begin(), initialNums.end(), nums.begin() + 1);
        
        // dp[i][j] = maxCoins if the last burst balloon is in the range (i, j), excluding i and j
        // dp[i][j] = max(nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]), where k is in range (i, j)
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        for(int len = 2; len <= N + 1; ++len){
            for(int i = 0; i + len <= N + 1; ++i){
                int j = i + len;
                for(int k = i + 1; k <= j - 1; ++k){
                    dp[i][j] = max(nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }
        
        return dp[0][N + 1];
    }
};