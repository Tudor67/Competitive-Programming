class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        const int ROWS = n;
        const int COLS = n;
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        
        for(const vector<int>& V: queries){
            int row1 = V[0];
            int col1 = V[1];
            int row2 = V[2];
            int col2 = V[3];
            
            res[row1][col1] += 1;
            if(col2 + 1 < COLS){
                res[row1][col2 + 1] -= 1;
            }
            if(row2 + 1 < ROWS){
                res[row2 + 1][col1] -= 1;
            }
            if(row2 + 1 < ROWS && col2 + 1 < COLS){
                res[row2 + 1][col2 + 1] += 1;
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                res[row][col] += res[row][col - 1];
            }
        }

        for(int col = 0; col < COLS; ++col){
            for(int row = 1; row < ROWS; ++row){
                res[row][col] += res[row - 1][col];
            }
        }
        
        return res;
    }
};