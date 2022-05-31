class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          {0, -1}, {0, 1},
                                                          {1, -1}, {1, 0}, {1, 1}};
        const int N = grid.size();
        
        vector<vector<int>> dist(N, vector<int>(N, -1));
        queue<pair<int, int>> q;
        if(grid[0][0] == 0){
            dist[0][0] = 1;
            q.emplace(0, 0);
        }
        
        while(!q.empty() && dist[N - 1][N - 1] == -1){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N &&
                   grid[nextRow][nextCol] == 0 && dist[nextRow][nextCol] == -1){
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                    q.emplace(nextRow, nextCol);
                }
            }
        }
        
        return dist[N - 1][N - 1];
    }
};