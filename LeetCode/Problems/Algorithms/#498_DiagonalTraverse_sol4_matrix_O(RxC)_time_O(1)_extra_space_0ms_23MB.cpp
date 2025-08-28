class Solution {
private:
    void collectDiagonalValues(vector<vector<int>>& mat, int startRow, int startCol, vector<int>& res){
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        const int RES_INITIAL_SIZE = res.size();

        for(int row = startRow, col = startCol; row >= 0 && col < COLS; --row, ++col){
            res.push_back(mat[row][col]);
        }

        if((startRow + startCol) % 2 == 1){
            reverse(res.begin() + RES_INITIAL_SIZE, res.end());
        }
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<int> res;
        res.reserve(ROWS * COLS);

        for(int startRow = 0; startRow < ROWS; ++startRow){
            collectDiagonalValues(mat, startRow, 0, res);
        }

        for(int startCol = 1; startCol < COLS; ++startCol){
            collectDiagonalValues(mat, ROWS - 1, startCol, res);
        }
        
        return res;
    }
};