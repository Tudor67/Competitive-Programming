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

        vector<int> count(3);
        if(COLS % 2 == 1){
            for(int row = 0; row < ROWS / 2; ++row){
                count[grid[row][COLS / 2] + grid[ROWS - 1 - row][COLS / 2]] += 1;
            }
        }

        if(ROWS % 2 == 1){
            for(int col = 0; col < COLS / 2; ++col){
                count[grid[ROWS / 2][col] + grid[ROWS / 2][COLS - 1 - col]] += 1;
            }
        }

        minFlips += count[1];
        if(count[2] % 2 == 1 && count[1] == 0){
            minFlips += 2;
        }

        return minFlips;
    }
};