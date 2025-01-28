class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<bool>> canCommunicate(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            int prevServerRow = -1;
            int prevServerCol = -1;
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    if(prevServerRow != -1){
                        canCommunicate[prevServerRow][prevServerCol] = true;
                        canCommunicate[row][col] = true;
                    }
                    prevServerRow = row;
                    prevServerCol = col;
                }
            }
        }

        for(int col = 0; col < COLS; ++col){
            int prevServerRow = -1;
            int prevServerCol = -1;
            for(int row = 0; row < ROWS; ++row){
                if(grid[row][col] == 1){
                    if(prevServerRow != -1){
                        canCommunicate[prevServerRow][prevServerCol] = true;
                        canCommunicate[row][col] = true;
                    }
                    prevServerRow = row;
                    prevServerCol = col;
                }
            }
        }

        int isolatedServers = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(!canCommunicate[row][col]){
                    isolatedServers += 1;
                }
            }
        }

        return ROWS * COLS - isolatedServers;
    }
};