class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        long long gridSum = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                gridSum += grid[row][col];
            }
        }

        long long topSum = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                topSum += grid[row][col];
            }
            if(topSum * 2 == gridSum){
                return true;
            }
        }

        long long leftSum = 0;
        for(int col = 0; col < COLS; ++col){
            for(int row = 0; row < ROWS; ++row){
                leftSum += grid[row][col];
            }
            if(leftSum * 2 == gridSum){
                return true;
            }
        }

        return false;
    }
};