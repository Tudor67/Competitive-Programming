class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        static const int INF = 1e8;
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 2){
                    q.push({row, col});
                    dist[row][col] = 0;
                }
            }
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   grid[nextRow][nextCol] == 1 && dist[row][col] + 1 < dist[nextRow][nextCol]){
                    q.push({nextRow, nextCol});
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                }
            }
        }
        
        int answer = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    answer = max(answer, dist[row][col]);
                }
            }
        }
        
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};