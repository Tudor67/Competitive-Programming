class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        static const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    dist[row][col] = 0;
                    q.push({row, col});
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
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(dist[row][col] + 1 < dist[nextRow][nextCol]){
                        dist[nextRow][nextCol] = dist[row][col] + 1;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }

        int res = -1;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0 && dist[row][col] != INF){
                    res = max(res, dist[row][col]);
                }
            }
        }

        return res;
    }
};