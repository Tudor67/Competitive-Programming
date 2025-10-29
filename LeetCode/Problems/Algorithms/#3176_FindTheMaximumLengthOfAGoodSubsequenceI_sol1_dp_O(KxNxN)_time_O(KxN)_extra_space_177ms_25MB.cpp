class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int N = nums.size();

        // dp[k][i]: max length of a sequence with the last element nums[i]
        //           and at most k distinct adjacent elements
        vector<vector<int>> dp(k + 1, vector<int>(N));

        for(int distinct = 0; distinct <= k; ++distinct){
            for(int i = 0; i < N; ++i){
                dp[distinct][i] = 1;
                for(int j = 0; j < i; ++j){
                    if(nums[j] == nums[i]){
                        dp[distinct][i] = max(dp[distinct][i], dp[distinct][j] + 1);
                    }else if(distinct >= 1){
                        dp[distinct][i] = max(dp[distinct][i], dp[distinct - 1][j] + 1);
                    }
                }
            }
        }

        return *max_element(dp[k].begin(), dp[k].end());
    }
};