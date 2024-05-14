class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> res(ROWS - 2, vector<int>(COLS - 2));
        for(int row = 0; row + 2 < ROWS; ++row){
            for(int col = 0; col + 2 < COLS; ++col){
                res[row][col] = grid[row][col];
                for(int rowShift = 0; rowShift <= 2; ++rowShift){
                    for(int colShift = 0; colShift <= 2; ++colShift){
                        res[row][col] = max(res[row][col], grid[row + rowShift][col + colShift]);
                    }
                }
            }
        }

        return res;
    }
};