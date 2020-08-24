class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = triangle.size();
        vector<vector<int>> dp(2, vector<int>(N));
        
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < N; ++i){
            dp[i % 2][0] = triangle[i][0] + dp[(i + 1) % 2][0];
            dp[i % 2][i] = triangle[i][i] + dp[(i + 1) % 2][i - 1];
            for(int j = 1; j < i; ++j){
                dp[i % 2][j] = triangle[i][j] + min(dp[(i + 1) % 2][j - 1], dp[(i + 1) % 2][j]);
            }
        }
        
        return *min_element(dp[(N - 1) % 2].begin(), dp[(N - 1) % 2].end());
    }
};