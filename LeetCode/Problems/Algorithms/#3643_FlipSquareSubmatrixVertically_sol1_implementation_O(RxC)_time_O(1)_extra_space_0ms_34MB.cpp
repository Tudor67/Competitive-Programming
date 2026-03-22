class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> res = grid;
        for(int col = y; col < y + k; ++col){
            for(int row1 = x, row2 = x + k - 1; row1 < row2; ++row1, --row2){
                swap(res[row1][col], res[row2][col]);
            }
        }

        return res;
    }
};