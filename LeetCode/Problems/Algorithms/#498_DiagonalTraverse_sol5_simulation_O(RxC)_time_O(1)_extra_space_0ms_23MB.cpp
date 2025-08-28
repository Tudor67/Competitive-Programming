class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int ROWS = mat.size();
        const int COLS = mat[0].size();

        vector<int> res(ROWS * COLS);

        int row = 0;
        int col = 0;
        for(int i = 0; i < (int)res.size(); ++i){
            res[i] = mat[row][col];
            if((row + col) % 2 == 0){
                if(col == COLS - 1){
                    row += 1;
                }else if(row == 0){
                    col += 1;
                }else{
                    row -= 1;
                    col += 1;
                }
            }else{
                if(row == ROWS - 1){
                    col += 1;
                }else if(col == 0){
                    row += 1;
                }else{
                    row += 1;
                    col -= 1;
                }
            }
        }

        return res;
    }
};