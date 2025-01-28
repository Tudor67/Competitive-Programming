class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> serversInRow(ROWS);
        vector<int> serversInCol(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    serversInRow[row] += 1;
                    serversInCol[col] += 1;
                }
            }
        }

        int goodServers = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    if(serversInRow[row] >= 2 || serversInCol[col] >= 2){
                        goodServers += 1;
                    }
                }
            }
        }

        return goodServers;
    }
};