class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        // dp[i][diff]: length of the longest arithmetic subsequence that ends with nums[i]
        //              and the difference between consecutive terms is equal to diff
        vector<vector<int>> dp(N, vector<int>(2 * MAX_NUM + 1, 1));
        int maxLen = 1;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = nums[i] - nums[j] + MAX_NUM;
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                maxLen = max(maxLen, dp[i][diff]);
            }
        }
        
        return maxLen;
    }
};