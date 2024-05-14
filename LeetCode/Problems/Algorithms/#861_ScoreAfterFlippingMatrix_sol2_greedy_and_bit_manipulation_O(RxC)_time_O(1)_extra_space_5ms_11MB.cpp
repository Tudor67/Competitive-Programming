class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int rowMask = 0;
        for(int row = 0; row < ROWS; ++row){
            if(grid[row][0] == 0){
                rowMask |= (1 << row);
            }
        }

        int colMask = 0;
        for(int col = 0; col < COLS; ++col){
            int colOnes = 0;
            for(int row = 0; row < ROWS; ++row){
                int isFlipped = (rowMask >> row) & 1;
                colOnes += (grid[row][col] ^ isFlipped);
            }
            if(colOnes < ROWS - colOnes){
                colMask |= (1 << col);
            }
        }

        int maxScore = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int isFlipped = ((rowMask >> row) ^ (colMask >> col)) & 1;
                if(grid[row][col] ^ isFlipped){
                    maxScore += (1 << (COLS - 1 - col));
                }
            }
        }

        return maxScore;
    }
};