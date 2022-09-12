class Solution {
private:
    const int INF = 5e8;
    
    int getVal(vector<vector<int>>& matrix, int row, int col){
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
            return INF;
        }
        return matrix[row][col];
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        
        // At iteration row:
        //    dp[row % 2][col]: min sum of a falling path starting in the first row and
        //                      ending at position (row, col)
        vector<vector<int>> dp(2, vector<int>(N));
        for(int col = 0; col < N; ++col){
            dp[0][col] = matrix[0][col];
        }
        
        for(int row = 1; row < N; ++row){
            for(int col = 0; col < N; ++col){
                dp[row % 2][col] = matrix[row][col] +
                                   min({getVal(dp, (row - 1) % 2, col - 1),
                                        getVal(dp, (row - 1) % 2, col),
                                        getVal(dp, (row - 1) % 2, col + 1)});
            }
        }
        
        return *min_element(dp[(N - 1) % 2].begin(), dp[(N - 1) % 2].end());
    }
};