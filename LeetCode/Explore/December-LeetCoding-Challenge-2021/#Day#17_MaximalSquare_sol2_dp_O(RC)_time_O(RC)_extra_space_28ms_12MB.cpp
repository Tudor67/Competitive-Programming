class Solution {
private:
    int valAt(vector<vector<int>>& a, int row, int col){
        const int ROWS = a.size();
        const int COLS = a[0].size();
        if(0 <= row && row < ROWS && 0 <= col && col < COLS){
            return a[row][col];
        }
        return 0;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        int maxSide = 0;
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == '1'){
                    dp[row][col] = 1 + min({valAt(dp, row - 1, col),
                                            valAt(dp, row, col - 1),
                                            valAt(dp, row - 1, col - 1)});
                    maxSide = max(maxSide, dp[row][col]);
                }
            }
        }
        
        return maxSide * maxSide;
    }
};