class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        vector<vector<int>> res = mat;
        for(int iteration = 1; iteration <= min(ROWS, COLS) - 1; ++iteration){
            for(int row = 0; row < ROWS - iteration; ++row){
                for(int col = 0; col < COLS - iteration; ++col){
                    if(res[row][col] > res[row + 1][col + 1]){
                        swap(res[row][col], res[row + 1][col + 1]);
                    }
                }
            }
        }
        
        return res;
    }
};