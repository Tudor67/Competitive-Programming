class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        vector<vector<vector<int>>> dp(2 * N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        // dp[i][d1][d2]: max cherries after i steps if robot1 is at d1th cell and robot2 is at the d2th cell
        
        dp[0][0][0] = grid[0][0];
        for(int step = 1; step <= 2 * N - 2; ++step){
            for(int d1 = 0; d1 < N; ++d1){
                for(int d2 = 0; d2 < N; ++d2){
                    int row1 = d1 < N ? d1 : 1 + (d1 % N);
                    int col1 = step - row1;
                    int row2 = d2 < N ? d2 : 1 + (d2 % N);
                    int col2 = step - row2;
                    if(0 <= col1 && col1 < N && 0 <= col2 && col2 < N && grid[row1][col1] != -1 && grid[row2][col2] != -1){
                        int cherries = grid[row1][col1] + (row1 != row2 || col1 != col2) * grid[row2][col2];
                        for(const pair<int, int>& P: vector<pair<int, int>>{{-1, -1}, {-1, 0}, {0, -1}, {0, 0}}){
                            int prevD1 = d1 + P.first;
                            int prevD2 = d2 + P.second;
                            if(0 <= prevD1 && 0 <= prevD2){
                                dp[step][d1][d2] = max(cherries + dp[step - 1][prevD1][prevD2], dp[step][d1][d2]);
                            }
                        }
                    }
                }
            }
        }
        
        return max(0, dp[2 * N - 2][N - 1][N - 1]);
    }
};