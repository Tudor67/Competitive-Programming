class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        
        // dp[i][j] == true,  if it is possible to split nums[i .. j]
        //                    into (j - i + 1) non-empty arrays
        // dp[i][j] == false, otherwise
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            dp[i][i] = true;
        }
        
        for(int len = 2; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                int prefSum = 0;
                int suffSum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
                for(int k = i; k + 1 <= j; ++k){
                    prefSum += nums[k];
                    suffSum -= nums[k];
                    if(k == i || prefSum >= m){
                        if(k + 1 == j || suffSum >= m){
                            if(dp[i][k] && dp[k + 1][j]){
                                dp[i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return dp[0][N - 1];
    }
};