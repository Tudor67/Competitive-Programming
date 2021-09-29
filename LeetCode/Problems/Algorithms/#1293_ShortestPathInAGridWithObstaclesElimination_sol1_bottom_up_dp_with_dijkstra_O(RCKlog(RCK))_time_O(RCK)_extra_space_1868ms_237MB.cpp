class Solution {
private:
    bool isInsideGrid(int row, int col, const int& ROWS, const int& COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        // dp[i][j][k]: min distance from (0, 0) to (i, j) when we eliminate k obstacles
        int dp[ROWS][COLS][K + 1];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int k = 0; k <= K; ++k){
                    dp[row][col][k] = INF;
                }
            }
        }
        
        set<tuple<int, int, int, int>> stateSet;
        stateSet.insert({0, 0, 0, 0});
        dp[0][0][0] = 0;
        while(!stateSet.empty()){
            int row, col, k;
            tie(ignore, row, col, k) = *stateSet.begin();
            stateSet.erase(stateSet.begin());
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInsideGrid(nextRow, nextCol, ROWS, COLS)){
                    int nextK = k + grid[row][col];
                    if(nextK <= K && 1 + dp[row][col][k] < dp[nextRow][nextCol][nextK]){
                        auto it = stateSet.find({dp[nextRow][nextCol][nextK], nextRow, nextCol, nextK});
                        if(it != stateSet.end()){
                            stateSet.erase(it);
                        }
                        dp[nextRow][nextCol][nextK] = 1 + dp[row][col][k];
                        stateSet.insert({dp[nextRow][nextCol][nextK], nextRow, nextCol, nextK});
                    }
                }
            }
        }
        
        int answer = *min_element(dp[ROWS - 1][COLS - 1], dp[ROWS - 1][COLS - 1] + K + 1);
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};