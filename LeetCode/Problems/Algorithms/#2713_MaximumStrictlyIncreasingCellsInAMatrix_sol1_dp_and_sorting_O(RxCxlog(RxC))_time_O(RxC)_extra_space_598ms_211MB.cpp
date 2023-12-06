class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        // dp[row][col]: max length of a path ending at cell (row, col)
        // rowToMaxLen[row]: max(dp[row][0], dp[row][1], ..., dp[row][COLS - 1])
        // colToMaxLen[col]: max(dp[0][col], dp[1][col], ..., dp[ROWS - 1][col])
        vector<vector<int>> dp(ROWS, vector<int>(COLS));
        vector<int> rowToMaxLen(ROWS);
        vector<int> colToMaxLen(COLS);

        map<int, vector<pair<int, int>>> valToCells;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                valToCells[mat[row][col]].push_back({row, col});
            }
        }

        for(pair<const int, vector<pair<int, int>>>& P: valToCells){
            vector<pair<int, int>>& cells = P.second;
            for(const pair<int, int>& CELL: cells){
                int row = CELL.first;
                int col = CELL.second;
                dp[row][col] = 1 + max(rowToMaxLen[row], colToMaxLen[col]);
            }

            for(const pair<int, int>& CELL: cells){
                int row = CELL.first;
                int col = CELL.second;
                rowToMaxLen[row] = max(rowToMaxLen[row], dp[row][col]);
                colToMaxLen[col] = max(colToMaxLen[col], dp[row][col]);
            }
        }

        int res = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res = max(res, dp[row][col]);
            }
        }
        
        return res;
    }
};