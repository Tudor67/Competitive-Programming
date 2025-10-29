class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        const int N = nums.size();

        // dp[k][i]: max length of a sequence with the last element nums[i]
        //           and at most k distinct adjacent elements
        vector<vector<int>> dp(k + 1, vector<int>(N));

        for(int distinct = 0; distinct <= k; ++distinct){
            int prevMax = 0;
            unordered_map<int, int> currMaxOf;
            for(int i = 0; i < N; ++i){
                dp[distinct][i] = max(currMaxOf[nums[i]] + 1, prevMax + 1);
                currMaxOf[nums[i]] = dp[distinct][i];
                if(distinct >= 1){
                    prevMax = max(prevMax, dp[distinct - 1][i]);
                }
            }
        }

        return *max_element(dp[k].begin(), dp[k].end());
    }
};