class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = triangle.size();
        
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        for(int row = 1; row <= N - 1; ++row){
            dp[row][0] = triangle[row][0] + dp[row - 1][0];
            dp[row][row] = triangle[row][row] + dp[row - 1][row - 1];
            for(int col = 1; col <= row - 1; ++col){
                dp[row][col] = triangle[row][col] + min(dp[row - 1][col - 1], dp[row - 1][col]);
            }
        }
        
        return *min_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};