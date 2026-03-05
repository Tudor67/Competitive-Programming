class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int minFlips = 0;
        for(int row = 0; row < ROWS / 2; ++row){
            for(int col = 0; col < COLS / 2; ++col){
                int sum = grid[row][col] + grid[row][COLS - 1 - col] +
                          grid[ROWS - 1 - row][col] + grid[ROWS - 1 - row][COLS - 1 - col];
                minFlips += min(sum, 4 - sum);
            }
        }

        if(ROWS * COLS % 2 == 1){
            minFlips += grid[ROWS / 2][COLS / 2];
        }

        int midOnes = 0;
        int midFlips = 0;
        if(COLS % 2 == 1){
            for(int row = 0; row < ROWS / 2; ++row){
                midOnes += grid[row][COLS / 2];
                midOnes += grid[ROWS - 1 - row][COLS / 2];
                midFlips += (grid[row][COLS / 2] ^ grid[ROWS - 1 - row][COLS / 2]);
            }
        }

        if(ROWS % 2 == 1){
            for(int col = 0; col < COLS / 2; ++col){
                midOnes += grid[ROWS / 2][col];
                midOnes += grid[ROWS / 2][COLS - 1 - col];
                midFlips += (grid[ROWS / 2][col] ^ grid[ROWS / 2][COLS - 1 - col]);
            }
        }

        minFlips += midFlips;
        midOnes %= 4;
        minFlips += max(0, min(midOnes, 4 - midOnes) - midFlips);

        return minFlips;
    }
};