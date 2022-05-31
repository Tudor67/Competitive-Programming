class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        const int N = strs.size();
        const int ZEROS = m;
        const int ONES = n;
        
        // At step i:
        //    dp[i % 2][j][k]: size of the largest subset of strs[0 .. i] such that there are
        //                     at most j 0's and k 1's
        vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(2,
                                              vector<vector<int>>(ZEROS + 1,
                                                     vector<int>(ONES + 1))));
        
        int zeros = count(strs[0].begin(), strs[0].end(), '0');
        int ones = count(strs[0].begin(), strs[0].end(), '1');
        for(int j = zeros; j <= m; ++j){
            for(int k = ones; k <= n; ++k){
                dp[0][j][k] = 1;
            }
        }
        
        for(int i = 1; i < N; ++i){
            int zeros = count(strs[i].begin(), strs[i].end(), '0');
            int ones = count(strs[i].begin(), strs[i].end(), '1');
            for(int j = 0; j <= ZEROS; ++j){
                for(int k = 0; k <= ONES; ++k){
                    if(zeros <= j && ones <= k){
                        dp[i % 2][j][k] = max(dp[(i - 1) % 2][j][k], dp[(i - 1) % 2][j - zeros][k - ones] + 1);
                    }else{
                        dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
                    }
                }
            }
        }
        
        return dp[(N - 1) % 2][ZEROS][ONES];
    }
};