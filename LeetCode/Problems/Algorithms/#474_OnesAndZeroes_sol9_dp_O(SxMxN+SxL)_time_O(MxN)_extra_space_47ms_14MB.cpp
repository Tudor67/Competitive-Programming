class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]: size of the largest subset of strs such that
        //           there are at most i zeros and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for(string& str: strs){
            int zeros = count(str.begin(), str.end(), '0');
            int ones = (int)str.length() - zeros;

            for(int i = m; i >= zeros; --i){
                for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};