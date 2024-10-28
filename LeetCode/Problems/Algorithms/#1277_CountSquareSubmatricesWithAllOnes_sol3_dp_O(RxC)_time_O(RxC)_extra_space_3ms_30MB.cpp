class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int res = 0;
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1));
        for(int row = ROWS - 1; row >= 0; --row){
            for(int col = COLS - 1; col >= 0; --col){
                if(matrix[row][col] == 1){
                    dp[row][col] = 1 + min({dp[row + 1][col],
                                            dp[row][col + 1],
                                            dp[row + 1][col + 1]});
                    res += dp[row][col];
                }
            }
        }

        return res;
    }
};