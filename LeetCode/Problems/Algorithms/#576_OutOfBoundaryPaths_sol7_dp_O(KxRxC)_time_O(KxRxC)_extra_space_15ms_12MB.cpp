class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int ROWS = m;
        const int COLS = n;
        const int MODULO = 1e9 + 7;
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // dp[k][row][col]: number of paths of length k from (startRow + 1, startCol + 1) to (row, col)
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(ROWS + 2, vector<int>(COLS + 2)));
        dp[0][startRow + 1][startColumn + 1] = 1;
        for(int k = 0; k + 1 <= maxMove; ++k){
            for(int row = 1; row <= ROWS; ++row){
                for(int col = 1; col <= COLS; ++col){
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int nextRow = row + DIRECTION.first;
                        int nextCol = col + DIRECTION.second;
                        dp[k + 1][nextRow][nextCol] += dp[k][row][col];
                        dp[k + 1][nextRow][nextCol] %= MODULO;
                    }
                }
            }
        }

        int res = 0;
        for(int k = 1; k <= maxMove; ++k){
            for(int row = 0; row <= ROWS + 1; ++row){
                for(int col = 0; col <= COLS + 1; ++col){
                    if(row == 0 || row == ROWS + 1 || col == 0 || col == COLS + 1){
                        res += dp[k][row][col];
                        res %= MODULO;
                    }
                }
            }
        }

        return res;
    }
};