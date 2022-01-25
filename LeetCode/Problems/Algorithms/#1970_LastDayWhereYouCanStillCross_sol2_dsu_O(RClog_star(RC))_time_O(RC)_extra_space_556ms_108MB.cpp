class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
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
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:
    int getIdx(int row, int col, int COLS){
        return row * COLS + col;
    }
    
public:
    int latestDayToCross(int ROWS, int COLS, vector<vector<int>>& cells) {
        DSU dsu(getIdx(ROWS, COLS, COLS));
        int leftColIdx = getIdx(1, 1, COLS);
        int rightColIdx = getIdx(1, COLS, COLS);
        for(int row = 1; row <= ROWS; ++row){
            dsu.join(leftColIdx, getIdx(row, 1, COLS));
            dsu.join(rightColIdx, getIdx(row, COLS, COLS));
        }
        
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          {0, -1}, {0, 1},
                                                          {1, -1}, {1, 0}, {1, 1}};
        vector<vector<bool>> vis(ROWS + 2, vector<bool>(COLS + 2, false));
        
        for(int day = 0; day < ROWS * COLS; ++day){
            int row = cells[day][0];
            int col = cells[day][1];
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(vis[nextRow][nextCol]){
                    dsu.join(getIdx(row, col, COLS), getIdx(nextRow, nextCol, COLS));
                }
            }
            
            vis[row][col] = true;
            
            if(dsu.find(leftColIdx) == dsu.find(rightColIdx)){
                return day;
            }
        }
        
        return -1;
    }
};