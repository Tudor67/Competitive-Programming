class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N);
        parent.resize(N);
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
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:
    int getIdx(int row, int col, const int& COLS){
        return (row * COLS + col);
    }
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        DSU dsu(getIdx(ROWS - 1, COLS - 1, COLS) + 1);
        
        unordered_map<int, int> prevColOf;
        for(int row = 0; row < ROWS; ++row){
            prevColOf.clear();
            for(int col = 0; col < COLS; ++col){
                int val = matrix[row][col];
                if(prevColOf.count(val)){
                    dsu.join(getIdx(row, prevColOf[val], COLS), getIdx(row, col, COLS));
                }
                prevColOf[val] = col;
            }
        }
        
        unordered_map<int, int> prevRowOf;
        for(int col = 0; col < COLS; ++col){
            prevRowOf.clear();
            for(int row = 0; row < ROWS; ++row){
                int val = matrix[row][col];
                if(prevRowOf.count(val)){
                    dsu.join(getIdx(prevRowOf[val], col, COLS), getIdx(row, col, COLS));
                }
                prevRowOf[val] = row;
            }
        }
        
        vector<tuple<int, int, int>> sortedValRowCol;
        sortedValRowCol.reserve(ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                sortedValRowCol.emplace_back(matrix[row][col], row, col);
            }
        }
        
        sort(sortedValRowCol.begin(), sortedValRowCol.end());
        
        vector<int> rankVector(ROWS * COLS);
        for(const tuple<int, int, int>& T: sortedValRowCol){
            int val, row, col;
            tie(val, row, col) = T;
            
            int rank = 1;
            for(int r = 0; r < ROWS; ++r){
                rank = max(rank, (int)(matrix[r][col] != val) + rankVector[dsu.find(getIdx(r, col, COLS))]);
            }
            
            for(int c = 0; c < COLS; ++c){
                rank = max(rank, (int)(matrix[row][c] != val) + rankVector[dsu.find(getIdx(row, c, COLS))]);
            }
            
            rankVector[dsu.find(getIdx(row, col, COLS))] = rank;
        }
        
        vector<vector<int>> res(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[row][col] = rankVector[dsu.find(getIdx(row, col, COLS))];
            }
        }
        
        return res;
    }
};