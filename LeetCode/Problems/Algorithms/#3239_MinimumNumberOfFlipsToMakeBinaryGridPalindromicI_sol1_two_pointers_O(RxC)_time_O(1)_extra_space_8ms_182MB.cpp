class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int rowMinFlips = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS / 2; ++col){
                rowMinFlips += (grid[row][col] ^ grid[row][COLS - 1 - col]);
            }
        }

        int colMinFlips = 0;
        for(int col = 0; col < COLS; ++col){
            for(int row = 0; row < ROWS / 2; ++row){
                colMinFlips += (grid[row][col] ^ grid[ROWS - 1 - row][col]);
            }
        }

        return min(rowMinFlips, colMinFlips);
    }
};