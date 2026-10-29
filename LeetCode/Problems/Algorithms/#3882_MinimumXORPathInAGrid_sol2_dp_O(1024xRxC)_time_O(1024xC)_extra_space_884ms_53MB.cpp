class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MAX_XOR = 1023;

        vector<vector<vector<bool>>> isPossible(2, vector<vector<bool>>(COLS, vector<bool>(MAX_XOR + 1)));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int xorVal = 0; xorVal <= MAX_XOR; ++xorVal){
                    isPossible[row % 2][col][xorVal] =
                       ((row == 0 && col == 0 && grid[row][col] == xorVal) ||
                        (row > 0 && isPossible[(row - 1) % 2][col][xorVal ^ grid[row][col]]) ||
                        (col > 0 && isPossible[row % 2][col - 1][xorVal ^ grid[row][col]]));
                }
            }
        }

        for(int xorVal = 0; xorVal <= MAX_XOR; ++xorVal){
            if(isPossible[(ROWS - 1) % 2][COLS - 1][xorVal]){
                return xorVal;
            }
        }

        return -1;
    }
};