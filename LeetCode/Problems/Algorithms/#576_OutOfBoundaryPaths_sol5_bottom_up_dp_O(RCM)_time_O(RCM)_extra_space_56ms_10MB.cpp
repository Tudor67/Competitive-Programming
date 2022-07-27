class Solution {
public:
    int findPaths(int ROWS, int COLS, int maxMove, int startRow, int startCol) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int MODULO = 1e9 + 7;
        
        // dp[k][row][col]: number of paths from (startRow + 1, startCol + 1) to (row, col)
        //                  when we make k moves
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(ROWS + 2, vector<int>(COLS + 2)));
        dp[0][startRow + 1][startCol + 1] = 1;
        
        int res = 0;
        for(int moves = 1; moves <= maxMove; ++moves){
            for(int row = 0; row <= ROWS + 1; ++row){
                for(int col = 0; col <= COLS + 1; ++col){
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(1 <= neighRow && neighRow <= ROWS && 1 <= neighCol && neighCol <= COLS){
                            dp[moves][row][col] += dp[moves - 1][neighRow][neighCol];
                            dp[moves][row][col] %= MODULO;
                        }
                    }
                    if(row == 0 || row == ROWS + 1 || col == 0 || col == COLS + 1){
                        res += dp[moves][row][col];
                        res %= MODULO;
                    }
                }
            }
        }
        
        return res;
    }
};