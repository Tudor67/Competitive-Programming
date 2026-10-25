class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int MAX_PATH_LEN = ROWS + COLS - 1;

        vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(COLS, vector<bool>(MAX_PATH_LEN + 1)));
        
        if(grid[0][0] == '('){
            dp[0][0][1] = true;
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int balance = 0; balance <= row + col + 1; ++balance){
                    if(!dp[row % 2][col][balance]){
                        continue;
                    }

                    if(row + 1 < ROWS){
                        if(grid[row + 1][col] == '('){
                            dp[(row + 1) % 2][col][balance + 1] = true;
                        }else if(balance >= 1){
                            dp[(row + 1) % 2][col][balance - 1] = true;
                        }
                    }

                    if(col + 1 < COLS){
                        if(grid[row][col + 1] == '('){
                            dp[row % 2][col + 1][balance + 1] = true;
                        }else if(balance >= 1){
                            dp[row % 2][col + 1][balance - 1] = true;
                        }
                    }

                    if(row != ROWS - 1){
                        dp[row % 2][col][balance] = false;
                    }
                }
            }
        }

        return dp[(ROWS - 1) % 2][COLS - 1][0];
    }
};