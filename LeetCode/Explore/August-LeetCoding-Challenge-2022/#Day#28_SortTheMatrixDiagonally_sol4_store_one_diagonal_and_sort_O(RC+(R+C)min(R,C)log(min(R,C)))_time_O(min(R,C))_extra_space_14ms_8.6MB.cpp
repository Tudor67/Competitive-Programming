class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        
        vector<int> diagonalValues;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                if(startRow == 0 || startCol == 0){
                    diagonalValues.clear();
                    
                    int row = startRow;
                    int col = startCol;
                    while(row < ROWS && col < COLS){
                        diagonalValues.push_back(mat[row][col]);
                        row += 1;
                        col += 1;
                    }
                    
                    sort(diagonalValues.begin(), diagonalValues.end());
                    
                    for(int i = 0; i < (int)diagonalValues.size(); ++i){
                        res[startRow + i][startCol + i] = diagonalValues[i];
                    }
                }
            }
        }
        
        return res;
    }
};