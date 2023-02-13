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
            
            for(int row = row1; row <= row2; ++row){
                res[row][col1] += 1;
                if(col2 + 1 < COLS){
                    res[row][col2 + 1] -= 1;
                }
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                res[row][col] += res[row][col - 1];
            }
        }
        
        return res;
    }
};