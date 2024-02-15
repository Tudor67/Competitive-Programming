class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        // dp[i][j]: min operations to make nums[0 .. i] sorted in non-decreasing order
        //           such that the last element is equal to number j
        vector<vector<int>> dp(N, vector<int>(4, INF));
        for(int j = 1; j <= 3; ++j){
            dp[0][j] = (int)(nums[0] != j);
        }

        for(int i = 1; i < N; ++i){
            for(int j = 1; j <= 3; ++j){
                for(int k = 1; k <= j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + (int)(nums[i] != j));
                }
            }
        }

        return *min_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};