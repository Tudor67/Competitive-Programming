class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int MODULO = 1e9 + 7;
        const int ROWS = m;
        const int COLS = n;
        
        // dp[row][col][k]: number of paths (% MODULO) to move the ball to position (row, col) in k steps/moves
        vector<vector<vector<int>>> dp(ROWS + 2, vector<vector<int>>(COLS + 2, vector<int>(maxMove + 1, 0)));
        dp[startRow + 1][startColumn + 1][0] = 1;
        
        for(int move = 0; move <= maxMove - 1; ++move){
            for(int row = 1; row <= ROWS; ++row){
                for(int col = 1; col <= COLS; ++col){
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        int nextMove = move + 1;
                        dp[nextRow][nextCol][nextMove] += dp[row][col][move];
                        dp[nextRow][nextCol][nextMove] %= MODULO;
                    }
                }
            }
        }
        
        int answer = 0;
        for(int row = 0; row <= ROWS + 1; ++row){
            for(int col = 0; col <= COLS + 1; ++col){
                if(row == 0 || row == ROWS + 1 || col == 0 || col == COLS + 1){
                    for(int move = 0; move <= maxMove; ++move){
                        answer += dp[row][col][move];
                        answer %= MODULO;
                    }
                }
            }
        }
        
        return answer;
    }
};