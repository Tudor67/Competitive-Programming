class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int newRows, int newCols) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        vector<vector<int>> newMat;
        if(ROWS * COLS == newRows * newCols){
            newMat.resize(newRows, vector<int>(newCols));
            for(int row = 0; row < ROWS; ++row){
                for(int col = 0; col < COLS; ++col){
                    int idx = row * COLS + col;
                    newMat[idx / newCols][idx % newCols] = mat[row][col];
                }
            }
        }else{
            newMat = mat;
        }
        
        return newMat;
    }
};