class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int newRows, int newCols) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        const int SIZE = ROWS * COLS;
        
        vector<vector<int>> newMat;
        if(SIZE == newRows * newCols){
            newMat.resize(newRows, vector<int>(newCols));
            for(int idx = 0; idx < SIZE; ++idx){
                newMat[idx / newCols][idx % newCols] = mat[idx / COLS][idx % COLS];
            }
        }else{
            newMat = mat;
        }
        
        return newMat;
    }
};