class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int N = triangle.size();
        vector<vector<int>> dp(2, vector<int>(N));
        dp[(N - 1) % 2] = triangle[N - 1];
        for(int row = N - 2; row >= 0; --row){
            for(int col = 0; col <= row; ++col){
                dp[row % 2][col] = triangle[row][col] + min(dp[(row + 1) % 2][col], dp[(row + 1) % 2][col + 1]);
            }
        }
        return dp[0][0];
    }
};