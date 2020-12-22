class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int N = grid.size();
        const int M = grid[0].size();
        
        vector<vector<int>> a(N + 2, vector<int>(M + 2, 0));
        for(int row = 1; row <= N; ++row){
            for(int col = 1; col <= M; ++col){
                a[row][col] = grid[row - 1][col - 1];
            }
        }
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(M + 2, vector<int>(M + 2, 0)));
        for(int row = N; row >= 1; --row){
            for(int col1 = 1; col1 <= M; ++col1){
                for(int col2 = 1; col2 <= M; ++col2){
                    int maxNextState = 0;
                    for(int nextCol1 = col1 - 1; nextCol1 <= col1 + 1; ++nextCol1){
                        for(int nextCol2 = col2 - 1; nextCol2 <= col2 + 1; ++nextCol2){
                            maxNextState = max(dp[(row + 1) % 2][nextCol1][nextCol2], maxNextState);
                        }
                    }
                    if(col1 == col2){
                        dp[row % 2][col1][col2] = a[row][col1] + maxNextState;
                    }else{
                        dp[row % 2][col1][col2] = a[row][col1] + a[row][col2] + maxNextState;
                    }
                }
            }
        }
        
        return dp[1][1][M];
    }
};