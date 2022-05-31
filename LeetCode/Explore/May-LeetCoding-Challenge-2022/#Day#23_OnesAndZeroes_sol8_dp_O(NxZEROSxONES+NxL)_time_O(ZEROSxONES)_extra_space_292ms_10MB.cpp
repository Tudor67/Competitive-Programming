class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        const int N = strs.size();
        const int ZEROS = m;
        const int ONES = n;
        
        // At step i:
        //    dp[j][k]: size of the largest subset of strs[0 .. i] such that there are
        //              at most j 0's and k 1's
        vector<vector<int>> dp(ZEROS + 1, vector<int>(ONES + 1));
        for(int i = 0; i < N; ++i){
            int zeros = count(strs[i].begin(), strs[i].end(), '0');
            int ones = count(strs[i].begin(), strs[i].end(), '1');
            for(int j = ZEROS; j >= zeros; --j){
                for(int k = ONES; k >= ones; --k){
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        
        return dp[ZEROS][ONES];
    }
};