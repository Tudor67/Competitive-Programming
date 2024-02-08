class Solution {
private:
    int getRangeSum(int l, int r, vector<int>& prefSum){
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }

public:
    bool canSplitArray(vector<int>& nums, int m) {
        const int N = nums.size();

        vector<int> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        // dp[i][j] == true,  if it is possible to split nums[i .. j]
        //                    into (j - i + 1) non-empty arrays
        // dp[i][j] == false, otherwise
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            dp[i][i] = true;
            dp[i][min(N - 1, i + 1)] = true;
        }
        
        for(int len = 3; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(dp[i][j - 1] && getRangeSum(i, j - 1, prefSum) >= m){
                    dp[i][j] = true;
                }
                if(dp[i + 1][j] && getRangeSum(i + 1, j, prefSum) >= m){
                    dp[i][j] = true;
                }
            }
        }
        
        return dp[0][N - 1];
    }
};