class Solution {
private:
    const int MODULO = 1e9 + 7;
    const vector<pair<int, int>> DIRECTIONS = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                               {2, -1}, {2, 1}, {1, -2}, {1, 2}};

public:
    int knightDialer(int n) {
        // At nth iteration:
        //    dp[row][col][n % 2]: number of paths of length n ending at cell (row, col)
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(2)));
        for(int row = 0; row < 4; ++row){
            for(int col = 0; col < 3; ++col){
                dp[row][col][1] = 1;
            }
        }
        dp[3][0][1] = 0;
        dp[3][2][1] = 0;

        for(int len = 2; len <= n; ++len){
            for(int row = 0; row < 4; ++row){
                for(int col = 0; col < 3; ++col){
                    if(!(row == 3 && (col == 0 || col == 2))){
                        dp[row][col][len % 2] = 0;
                        for(const pair<int, int>& DIRECTION: DIRECTIONS){
                            int prevRow = row + DIRECTION.first;
                            int prevCol = col + DIRECTION.second;
                            if(0 <= prevRow && prevRow < 4 && 0 <= prevCol && prevCol < 3){
                                dp[row][col][len % 2] += dp[prevRow][prevCol][(len - 1) % 2];
                                dp[row][col][len % 2] %= MODULO;
                            }
                        }
                    }
                }
            }
        }

        int res = 0;
        for(int row = 0; row < 4; ++row){
            for(int col = 0; col < 3; ++col){
                res = (res + dp[row][col][n % 2]) % MODULO;
            }
        }

        return res;
    }
};