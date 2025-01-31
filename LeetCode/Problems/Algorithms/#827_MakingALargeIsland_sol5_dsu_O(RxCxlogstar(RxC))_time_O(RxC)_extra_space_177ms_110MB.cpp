class DSU{
private:
    vector<int> size;
    vector<int> parent;
public:
    DSU(const int N){
        size.assign(N, 1);
        parent.assign(N, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot){
            return;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }

    int getSize(int x){
        return size[find(x)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int maxIslandSize = 0;

        auto isInside = [&](int row, int col) -> int {
            return (0 <= row && row < ROWS && 0 <= col && col < COLS);
        };

        auto cellToIndex = [&](int row, int col) -> int {
            return row * COLS + col;
        };

        DSU dsu(cellToIndex(ROWS - 1, COLS - 1) + 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 1){
                    if(row + 1 < ROWS && grid[row + 1][col] == 1){
                        dsu.join(cellToIndex(row, col), cellToIndex(row + 1, col));
                    }
                    if(col + 1 < COLS && grid[row][col + 1] == 1){
                        dsu.join(cellToIndex(row, col), cellToIndex(row, col + 1));
                    }
                    maxIslandSize = max(maxIslandSize, dsu.getSize(cellToIndex(row, col)));
                }
            }
        }

        set<int> neighSet;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == 0){
                    neighSet.clear();
                    for(const pair<int, int>& DIRECTION: DIRECTIONS){
                        int neighRow = row + DIRECTION.first;
                        int neighCol = col + DIRECTION.second;
                        if(isInside(neighRow, neighCol) && grid[neighRow][neighCol] == 1){
                            neighSet.insert(dsu.find(cellToIndex(neighRow, neighCol)));
                        }
                    }

                    int islandSize = 1;
                    for(int neigh: neighSet){
                        islandSize += dsu.getSize(neigh);
                    }

                    maxIslandSize = max(maxIslandSize, islandSize);
                }
            }
        }

        return maxIslandSize;
    }
};