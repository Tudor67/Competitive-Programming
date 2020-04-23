class Solution {
private:
    const vector<pair<int, int>> DIR = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void bfs(const pair<int, int>& src, vector<vector<bool>>& vis, int& cnt){
        if(!vis[src.first][src.second]){
            vis[src.first][src.second] = true;
            ++cnt;
            
            queue<pair<int, int>> q;
            q.push(src);
            
            while(!q.empty()){
                pair<int, int> pos = q.front();
                q.pop();

                for(const pair<int, int>& dir: DIR){
                    int new_i = pos.first + dir.first;
                    int new_j = pos.second + dir.second;
                    if(new_i >= 0 && new_i < vis.size() &&
                       new_j >= 0 && new_j < vis[new_i].size() &&
                       !vis[new_i][new_j]){
                        vis[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        if(!grid.empty()){
            vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
            for(int i = 0; i < vis.size(); ++i){
                for(int j = 0; j < vis[i].size(); ++j){
                    if(grid[i][j] == '1'){
                        vis[i][j] = false;
                    }else{
                        vis[i][j] = true;
                    }
                }
            }


            for(int i = 0; i < vis.size(); ++i){
                for(int j = 0; j < vis[i].size(); ++j){
                    bfs({i, j}, vis, cnt);
                }
            }
        }
        
        return cnt;
    }
};