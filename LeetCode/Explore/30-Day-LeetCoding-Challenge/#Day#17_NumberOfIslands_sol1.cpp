class Solution {
private:
    const vector<pair<int, int>> DIR = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void bfs(const pair<int, int>& src, vector<vector<char>>& grid, int& cnt){
        if(grid[src.first][src.second] == '1'){
            grid[src.first][src.second] = '0';
            ++cnt;
            
            queue<pair<int, int>> q;
            q.push(src);
            
            while(!q.empty()){
                pair<int, int> pos = q.front();
                q.pop();

                for(const pair<int, int>& dir: DIR){
                    int new_i = pos.first + dir.first;
                    int new_j = pos.second + dir.second;
                    if(new_i >= 0 && new_i < grid.size() &&
                       new_j >= 0 && new_j < grid[new_i].size() &&
                       grid[new_i][new_j] == '1'){
                        grid[new_i][new_j] = '0';
                        q.push({new_i, new_j});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                bfs({i, j}, grid, cnt);
            }
        }
        return cnt;
    }
};