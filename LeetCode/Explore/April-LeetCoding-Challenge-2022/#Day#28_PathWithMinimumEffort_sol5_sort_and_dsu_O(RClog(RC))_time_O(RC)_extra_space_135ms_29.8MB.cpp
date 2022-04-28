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
    int getIdx(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        const int START_IDX = getIdx(0, 0, COLS);
        const int END_IDX = getIdx(ROWS - 1, COLS - 1, COLS);
        
        using Edge = tuple<int, int, int>;
        vector<Edge> edges;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(col + 1 < COLS){
                    int diff = abs(heights[row][col] - heights[row][col + 1]);
                    edges.emplace_back(diff, getIdx(row, col, COLS), getIdx(row, col + 1, COLS));
                }
                if(row + 1 < ROWS){
                    int diff = abs(heights[row][col] - heights[row + 1][col]);
                    edges.emplace_back(diff, getIdx(row, col, COLS), getIdx(row + 1, col, COLS));
                }
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DSU dsu(ROWS * COLS);
        for(const Edge& EDGE: edges){
            int diff = get<0>(EDGE);
            int idx1 = get<1>(EDGE);
            int idx2 = get<2>(EDGE);
            
            dsu.join(idx1, idx2);
            
            if(dsu.find(START_IDX) == dsu.find(END_IDX)){
                return diff;
            }
        }
        
        return 0;
    }
};