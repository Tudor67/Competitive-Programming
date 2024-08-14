class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
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

    int join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot){
            return 0;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
        return 1;
    }
};

class Solution {
private:
    int getCellIndex(int row, int col, const int ROWS, const int COLS){
        return row * COLS + col;
    }

    int getUpNode(int row, int col, const int ROWS, const int COLS){
        return getCellIndex(row, col, ROWS, COLS);
    }

    int getRightNode(int row, int col, const int ROWS, const int COLS){
        return getCellIndex(row, col, ROWS, COLS) + ROWS * COLS;
    }

    int getDownNode(int row, int col, const int ROWS, const int COLS){
        return getCellIndex(row, col, ROWS, COLS) + 2 * ROWS * COLS;
    }

    int getLeftNode(int row, int col, const int ROWS, const int COLS){
        return getCellIndex(row, col, ROWS, COLS) + 3 * ROWS * COLS;
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int regions = 4 * ROWS * COLS;
        DSU dsu(4 * ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int upNode = getUpNode(row, col, ROWS, COLS);
                int rightNode = getRightNode(row, col, ROWS, COLS);
                int downNode = getDownNode(row, col, ROWS, COLS);
                int leftNode = getLeftNode(row, col, ROWS, COLS);
                if(grid[row][col] == ' '){
                    regions -= dsu.join(upNode, rightNode);
                    regions -= dsu.join(rightNode, downNode);
                    regions -= dsu.join(downNode, leftNode);
                }else if(grid[row][col] == '/'){
                    regions -= dsu.join(upNode, leftNode);
                    regions -= dsu.join(rightNode, downNode);
                }else{
                    regions -= dsu.join(upNode, rightNode);
                    regions -= dsu.join(downNode, leftNode);
                }

                if(col >= 1){
                    regions -= dsu.join(leftNode, getRightNode(row, col - 1, ROWS, COLS));
                }
                if(row >= 1){
                    regions -= dsu.join(upNode, getDownNode(row - 1, col, ROWS, COLS));
                }
            }
        }

        return regions;
    }
};