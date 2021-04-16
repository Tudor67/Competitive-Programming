class Solution {
private:
    using GridWithInts = vector<vector<int>>;
    using GridWithBools = vector<vector<bool>>;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool isValid(const GridWithInts& GRID, GridWithBools& vis, const int& N,
                 const pair<int, int>& SRC, const pair<int, int>& DEST, const int& T){
        for(int row = 0; row < N; ++row){
            fill(vis[row].begin(), vis[row].end(), false);
        }
        
        queue<pair<int, int>> q;
        if(GRID[SRC.first][SRC.second] <= T){
            q.push(SRC);
            vis[SRC.first][SRC.second] = true;
        }
        
        while(!q.empty() && !vis[DEST.first][DEST.second]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N &&
                   GRID[nextRow][nextCol] <= T && !vis[nextRow][nextCol]){
                    q.push({nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return vis[DEST.first][DEST.second];
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        GridWithBools vis(N, vector<bool>(N));
        int answer = -1;
        for(int t = 0; t <= N * N - 1; ++t){
            if(isValid(grid, vis, N, {0, 0}, {N - 1, N - 1}, t)){
                answer = t;
                break;
            }
        }
        return answer;
    }
};