class Solution {
private:
    bool isPossible(const pair<int, int>& START_POS, const pair<int, int>& END_POS,
                    const vector<vector<int>>& GRID, const int& MAX_T){
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        static vector<vector<bool>> vis;
        const int N = GRID.size();
        if((int)vis.size() != N){
            vis.resize(N);
            for(int row = 0; row < N; ++row){
                vis[row].resize(N);
            }
        }
        
        for(int row = 0; row < N; ++row){
            fill(vis[row].begin(), vis[row].end(), false);
        }
        
        queue<pair<int, int>> q;
        if(GRID[START_POS.first][START_POS.second] <= MAX_T){
            q.push(START_POS);
            vis[START_POS.first][START_POS.second] = true;
        }
        
        while(!q.empty() && !vis[END_POS.first][END_POS.second]){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < N && 0 <= nextCol && nextCol < N &&
                   !vis[nextRow][nextCol] && GRID[nextRow][nextCol] <= MAX_T){
                    q.push({nextRow, nextCol});
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return vis[END_POS.first][END_POS.second];
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        int l = 0;
        int r = N * N;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible({0, 0}, {N - 1, N - 1}, grid, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};