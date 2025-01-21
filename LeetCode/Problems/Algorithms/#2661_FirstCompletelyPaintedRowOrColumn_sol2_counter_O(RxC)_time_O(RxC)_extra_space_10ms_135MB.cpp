class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<int> rowOf(ROWS * COLS + 1);
        vector<int> colOf(ROWS * COLS + 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                rowOf[mat[row][col]] = row;
                colOf[mat[row][col]] = col;
            }
        }

        vector<int> paintedAtRow(ROWS);
        vector<int> paintedAtCol(COLS);
        for(int i = 0; i < (int)arr.size(); ++i){
            int row = rowOf[arr[i]];
            int col = colOf[arr[i]];
            paintedAtRow[row] += 1;
            paintedAtCol[col] += 1;
            if(paintedAtRow[row] == COLS || paintedAtCol[col] == ROWS){
                return i;
            }
        }
        
        return -1;
    }
};