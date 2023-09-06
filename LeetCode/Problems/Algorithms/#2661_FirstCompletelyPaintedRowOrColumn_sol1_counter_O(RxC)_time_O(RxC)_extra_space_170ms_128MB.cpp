class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        vector<int> rowOf(ROWS * COLS);
        vector<int> colOf(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowOf[mat[row][col] - 1] = row;
                colOf[mat[row][col] - 1] = col;
            }
        }
        
        vector<int> paintedAtRow(ROWS);
        vector<int> paintedAtCol(COLS);
        for(int i = 0; i < ROWS * COLS; ++i){
            int row = rowOf[arr[i] - 1];
            int col = colOf[arr[i] - 1];
            paintedAtRow[row] += 1;
            paintedAtCol[col] += 1;
            if(paintedAtRow[row] == COLS || paintedAtCol[col] == ROWS){
                return i;
            }
        }
        
        return -1;
    }
};