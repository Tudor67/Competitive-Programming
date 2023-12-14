class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> diff(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            int balance = 0;
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    balance -= 1;
                }else{
                    balance += 1;
                }
            }

            for(int col = 0; col < COLS; ++col){
                diff[row][col] += balance;
            }
        }

        for(int col = 0; col < COLS; ++col){
            int balance = 0;
            for(int row = 0; row < ROWS; ++row){
                if(grid[row][col] == 0){
                    balance -= 1;
                }else{
                    balance += 1;
                }
            }

            for(int row = 0; row < ROWS; ++row){
                diff[row][col] += balance;
            }
        }

        return diff;
    }
};