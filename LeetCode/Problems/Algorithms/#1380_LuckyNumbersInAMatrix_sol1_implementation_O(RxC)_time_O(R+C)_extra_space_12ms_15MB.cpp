class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int INF = 1e9;

        vector<int> minOfRow(ROWS, INF);
        vector<int> maxOfCol(COLS, -INF);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                minOfRow[row] = min(minOfRow[row], matrix[row][col]);
                maxOfCol[col] = max(maxOfCol[col], matrix[row][col]);
            }
        }

        vector<int> luckyNums;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == minOfRow[row] && matrix[row][col] == maxOfCol[col]){
                    luckyNums.push_back(matrix[row][col]);
                }
            }
        }

        return luckyNums;
    }
};