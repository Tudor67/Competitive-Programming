class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<int> onesRow(ROWS);
        vector<int> zerosRow(ROWS);
        vector<int> onesCol(COLS);
        vector<int> zerosCol(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    zerosRow[row] += 1;
                    zerosCol[col] += 1;
                }else{
                    onesRow[row] += 1;
                    onesCol[col] += 1;
                }
            }
        }
        
        vector<vector<int>> diff(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                diff[row][col] = onesRow[row] + onesCol[col] - zerosRow[row] - zerosCol[col];
            }
        }
        
        return diff;
    }
};