class Solution {
private:
    void bfs(const vector<pair<int, int>>& SOURCES, const vector<vector<int>>& GRID, vector<vector<int>>& dist){
        const int N = GRID.size();
        const int M = GRID[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> q;
        
        for(const pair<int, int>& P: SOURCES){
            dist[P.first][P.second] = 0;
            q.push(P);
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int new_i = i + DIRECTION.first;
                int new_j = j + DIRECTION.second;
                
                if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < M &&
                   GRID[new_i][new_j] == 1 && dist[new_i][new_j] == -1){
                    dist[new_i][new_j] = 1 + dist[i][j];
                    q.push({new_i, new_j});
                }
            }
        }
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int N = grid.size();
        const int M = grid[0].size();
        
        vector<pair<int, int>> sources;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(grid[i][j] == 2){
                    sources.push_back({i, j});
                }
            }
        }
        
        vector<vector<int>> dist(N, vector<int>(M, -1));
        bfs(sources, grid, dist);
        
        int answer = 0;
        for(int i = 0; answer != -1 && i < N; ++i){
            for(int j = 0; answer != -1 && j < M; ++j){
                answer = max(dist[i][j], answer);
                if(grid[i][j] == 1 && dist[i][j] == -1){
                    answer = -1;
                }
            }
        }
        
        return answer;
    }
};