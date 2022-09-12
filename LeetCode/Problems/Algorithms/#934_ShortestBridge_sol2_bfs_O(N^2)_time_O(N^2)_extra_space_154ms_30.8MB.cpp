class Solution {
private:
    const int WATER = 0;
    const int LAND = 1;
    const int INF = 1e9;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool isInside(int row, int col, const int& ROWS, const int& COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }
    
    void bfs(int startRow, int startCol, vector<vector<int>>& groupOf, int group){
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
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(groupOf[nextRow][nextCol] == LAND){
                        groupOf[nextRow][nextCol] = group;
                        q.emplace(nextRow, nextCol);
                    }
                }
            }
        }
    }
    
    void computeDistances(const vector<pair<int, int>>& SRC_CELLS, vector<vector<int>>& groupOf, vector<vector<int>>& dist){
        const int ROWS = groupOf.size();
        const int COLS = groupOf[0].size();
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                dist[row][col] = INF;
            }
        }
        
        queue<pair<int, int>> q;
        for(const pair<int, int>& POS: SRC_CELLS){
            int row = POS.first;
            int col = POS.second;
            dist[row][col] = 0;
            q.emplace(row, col);
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    if(dist[row][col] + 1 < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + 1;
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
        int group = LAND;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(groupOf[row][col] == LAND){
                    group += 1;
                    bfs(row, col, groupOf, group);
                }
            }
        }
        
        const int FIRST_GROUP = LAND + 1;
        const int SECOND_GROUP = LAND + 2;
        
        // src1: all (row, col) cells of FIRST_GROUP
        // src2: all (row, col) cells of SECOND_GROUP
        vector<pair<int, int>> src1;
        vector<pair<int, int>> src2;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(groupOf[row][col] == FIRST_GROUP){
                    src1.emplace_back(row, col);
                }else if(groupOf[row][col] == SECOND_GROUP){
                    src2.emplace_back(row, col);
                }
            }
        }
        
        // dist1[row][col]: distance to the closest cell of FIRST_GROUP
        // dist2[row][col]: distance to the closest cell of SECOND_GROUP
        vector<vector<int>> dist1(ROWS, vector<int>(COLS));
        vector<vector<int>> dist2(ROWS, vector<int>(COLS));
        
        computeDistances(src1, groupOf, dist1);
        computeDistances(src2, groupOf, dist2);
        
        int minZeros = ROWS + COLS;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == WATER){
                    int zeros = dist1[row][col] + dist2[row][col] - 1;
                    minZeros = min(minZeros, zeros);
                }
            }
        }
        
        return minZeros;
    }
};