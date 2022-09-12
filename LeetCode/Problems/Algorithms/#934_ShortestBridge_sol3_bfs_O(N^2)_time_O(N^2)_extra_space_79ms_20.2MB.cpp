class Solution {
private:
    bool isInside(int row, int col, const int& ROWS, const int& COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        // mark with 2 the second group (using a simple bfs)
        int startRow = 0;
        int startCol = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    startRow = row;
                    startCol = col;
                }
            }
        }
        
        vector<vector<int>> groupOf = grid;
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);
        groupOf[startRow][startCol] = 2;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(groupOf[nextRow][nextCol] == 1){
                        groupOf[nextRow][nextCol] = 2;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
        
        // compute min distance from group 2 to group 1
        // using a simple bfs which starts from group 2 and stops when hits group 1
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(groupOf[row][col] == 2){
                    q.emplace(row, col);
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(groupOf[nextRow][nextCol] == 0){
                        groupOf[nextRow][nextCol] = groupOf[row][col] + 1;
                        q.emplace(nextRow, nextCol);
                    }else if(groupOf[nextRow][nextCol] == 1){
                        return groupOf[row][col] - 2;
                    }
                }
            }
        }
        
        return -1;
    }
};