class Solution {
private:
    const int WATER = 0;
    const int LAND = 1;
    
    void bfs(int startRow, int startCol, vector<vector<int>>& groupOf, int group){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = groupOf.size();
        const int COLS = groupOf[0].size();
        
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);
        groupOf[startRow][startCol] = group;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(groupOf[nextRow][nextCol] == LAND){
                        groupOf[nextRow][nextCol] = group;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<vector<int>> groupOf = grid;
        int group = 2;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(groupOf[row][col] == LAND){
                    bfs(row, col, groupOf, group);
                    group += 1;
                }
            }
        }
        
        int minZeros = ROWS + COLS;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int col1 = 0; col1 < COLS; ++col1){
                if(groupOf[row1][col1] != WATER){
                    for(int row2 = row1; row2 < ROWS; ++row2){
                        for(int col2 = 0; col2 < COLS; ++col2){
                            if(groupOf[row2][col2] != WATER && groupOf[row2][col2] != groupOf[row1][col1]){
                                int zeros = abs(row2 - row1) + abs(col2 - col1) - 1;
                                minZeros = min(minZeros, zeros);
                            }
                        }
                    }
                }
            }
        }
        
        return minZeros;
    }
};