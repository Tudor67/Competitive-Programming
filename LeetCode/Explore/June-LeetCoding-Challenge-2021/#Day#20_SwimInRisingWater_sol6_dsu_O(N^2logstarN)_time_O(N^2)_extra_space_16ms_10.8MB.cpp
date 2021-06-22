class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        vector<vector<pair<int, int>>> positionsForValue(N * N);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                positionsForValue[grid[row][col]].push_back({row, col});
            }
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> vis(N, vector<bool>(N, false));
        DSU dsu(N * N);
        int minT = -1;
        for(int t = 0; t < N * N; ++t){
            for(const pair<int, int>& POS: positionsForValue[t]){
                int row = POS.first;
                int col = POS.second;
                vis[row][col] = true;
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int neighRow = row + DIRECTION.first;
                    int neighCol = col + DIRECTION.second;
                    if(0 <= neighRow && neighRow < N && 0 <= neighCol && neighCol < N && vis[neighRow][neighCol]){
                        dsu.join(row * N + col, neighRow * N + neighCol);
                    }
                }
            }
            if(dsu.find(0) == dsu.find((N - 1) * N + N - 1)){
                minT = t;
                break;
            }
        }
        
        return minT;
    }
};