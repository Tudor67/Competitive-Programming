class Solution {
public:
    int maxCoins(vector<int>& initialNums) {
        const int N = initialNums.size();
        
        vector<int> nums(N + 2, 1);
        copy(initialNums.begin(), initialNums.end(), nums.begin() + 1);
        
        // dp[l][r]: max coins in the range[l .. r]
        // dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + nums[l - 1] * nums[i] * nums[r + 1])
        //            with l <= i <= r and nums[0] == nums[N + 1] == 1
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        for(int size = 1; size <= N; ++size){
            for(int l = 1; l + size - 1 <= N; ++l){
                int r = l + size - 1;
                for(int i = l; i <= r; ++i){
                    dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i + 1][r] + nums[l - 1] * nums[i] * nums[r + 1]);
                }
            }
        }
        
        return dp[1][N];
    }
};