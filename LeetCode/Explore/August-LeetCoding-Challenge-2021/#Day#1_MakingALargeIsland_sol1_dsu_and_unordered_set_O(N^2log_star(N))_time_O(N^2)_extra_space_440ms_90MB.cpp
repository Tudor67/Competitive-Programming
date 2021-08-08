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
private:
    int getIdx(int row, int col, const int& N){
        return (row * N + col);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        DSU dsu(N * N);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 1){
                    if(col + 1 < N && grid[row][col + 1] == 1){
                        dsu.join(getIdx(row, col, N), getIdx(row, col + 1, N));
                    }
                    if(row + 1 < N && grid[row + 1][col] == 1){
                        dsu.join(getIdx(row, col, N), getIdx(row + 1, col, N));
                    }
                }
            }
        }
        
        unordered_map<int, int> groupSize;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 1){
                    int currentGroupIdx = dsu.find(getIdx(row, col, N));
                    groupSize[currentGroupIdx] += 1;
                }
            }
        }
        
        int maxAchievableGroupSize = 0;
        for(const pair<int, int>& P: groupSize){
            maxAchievableGroupSize = max(maxAchievableGroupSize, P.second);
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        unordered_set<int> neighGroups;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(grid[row][col] == 0){
                    neighGroups.clear();
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(0 <= neighRow && neighRow < N && 0 <= neighCol && neighCol < N && grid[neighRow][neighCol] == 1){
                            neighGroups.insert(dsu.find(getIdx(neighRow, neighCol, N)));
                        }
                    }
                    int neighGroupsTotalSize = 1;
                    for(int neighGroup: neighGroups){
                        neighGroupsTotalSize += groupSize[neighGroup];
                    }
                    maxAchievableGroupSize = max(maxAchievableGroupSize, neighGroupsTotalSize);
                }
            }
        }
        
        return maxAchievableGroupSize;
    }
};