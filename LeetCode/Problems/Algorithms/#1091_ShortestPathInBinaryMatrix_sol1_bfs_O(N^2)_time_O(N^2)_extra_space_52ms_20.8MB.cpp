class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int N = grid.size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        vector<vector<int>> dist(N, vector<int>(N));
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 0){
                    dist[row][col] = 0;
                }else{
                    dist[row][col] = -1;
                }
            }
        }
        
        queue<pair<int, int>> q;
        if(grid[0][0] == 0){
            q.push({0, 0});
            dist[0][0] = 1;
        }
        
        while(!q.empty() && dist[N - 1][N - 1] == 0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                bool isValid = (0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N &&
                                dist[nextRow][nextCol] == 0);
                if(isValid){
                    q.push({nextRow, nextCol});
                    dist[nextRow][nextCol] = 1 + dist[row][col];
                }
            }
        }
        
        if(dist[N - 1][N - 1] == 0){
            dist[N - 1][N - 1] = -1;
        }
        
        return dist[N - 1][N - 1];
    }
};