class DSU{
private:
    vector<int> sum;
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        sum.assign(N, 0);
        size.assign(N, 1);
        parent.assign(N, 0);
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
        sum[yRoot] += sum[xRoot];
    }

    void setSum(int x, int newSum){
        sum[find(x)] = newSum;
    }

    int getSum(int x){
        return sum[find(x)];
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        auto cellToIndex = [&](int row, int col) -> int {
            return row * COLS + col;
        };

        DSU dsu(cellToIndex(ROWS - 1, COLS - 1) + 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                dsu.setSum(cellToIndex(row, col), grid[row][col]);
            }
        }

        int maxCollectedFish = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] > 0){
                    if(row + 1 < ROWS && grid[row + 1][col] > 0){
                        dsu.join(cellToIndex(row, col), cellToIndex(row + 1, col));
                    }
                    if(col + 1 < COLS && grid[row][col + 1] > 0){
                        dsu.join(cellToIndex(row, col), cellToIndex(row, col + 1));
                    }
                    maxCollectedFish = max(maxCollectedFish, dsu.getSum(cellToIndex(row, col)));
                }
            }
        }

        return maxCollectedFish;
    }
};