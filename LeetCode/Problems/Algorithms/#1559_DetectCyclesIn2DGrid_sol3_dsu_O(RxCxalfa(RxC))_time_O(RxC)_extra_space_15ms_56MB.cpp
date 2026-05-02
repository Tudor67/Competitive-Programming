class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        size.assign(N, 1);
        parent.resize(N);
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
};

class Solution {
private:
    int getIndex(int row, int col, const int COLS){
        return row * COLS + col;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        DSU dsu(getIndex(ROWS - 1, COLS - 1, COLS) + 1);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int currIdx = getIndex(row, col, COLS);

                if(row + 1 < ROWS && grid[row][col] == grid[row + 1][col]){
                    int nextRowIdx = getIndex(row + 1, col, COLS);
                    if(dsu.find(currIdx) == dsu.find(nextRowIdx)){
                        return true;
                    }
                    dsu.join(currIdx, nextRowIdx);
                }

                if(col + 1 < COLS && grid[row][col] == grid[row][col + 1]){
                    int nextColIdx = getIndex(row, col + 1, COLS);
                    if(dsu.find(currIdx) == dsu.find(nextColIdx)){
                        return true;
                    }
                    dsu.join(currIdx, nextColIdx);
                }
            }
        }

        return false;
    }
};