class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        vector<vector<int>> sortedMat = mat;
        vector<int> diag;
        for(int startRow = 0; startRow <= ROWS - 1; ++startRow){
            for(int startCol = 0; startCol <= (startRow == 0 ? COLS - 1 : 0); ++startCol){
                diag.clear();
                for(int row = startRow, col = startCol; row < ROWS && col < COLS; ++row, ++col){
                    diag.push_back(mat[row][col]);
                }
                sort(diag.begin(), diag.end());
                for(int row = startRow, col = startCol, idx = 0; idx < diag.size(); ++row, ++col, ++idx){
                    sortedMat[row][col] = diag[idx];
                }
            }
        }
        return sortedMat;
    }
};