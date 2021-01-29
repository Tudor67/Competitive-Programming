class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        parent.resize(N + 1);
        rank.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
            }else{
                parent[yRoot] = xRoot;
            }
            if(rank[xRoot] == rank[yRoot]){
                rank[yRoot] += 1;
            }
        }
    }
};

class Solution {
private:
    int idxFrom(int row, int col, const int& COLS){
        return row * COLS + col;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        const int START_IDX = idxFrom(0, 0, COLS);
        const int END_IDX = idxFrom(ROWS - 1, COLS - 1, COLS);
        
        vector<tuple<int, int, int>> edges;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    bool isInside = (0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS);
                    if(isInside){
                        int effort = abs(heights[row][col] - heights[nextRow][nextCol]);
                        edges.push_back({effort, idxFrom(row, col, COLS), idxFrom(nextRow, nextCol, COLS)});
                    }
                }
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int answer = 0;
        DSU dsu(END_IDX);
        for(const tuple<int, int, int>& EDGE: edges){
            int effort = get<0>(EDGE);
            int idx1 = get<1>(EDGE);
            int idx2 = get<2>(EDGE);
            dsu.unite(idx1, idx2);
            if(dsu.find(START_IDX) == dsu.find(END_IDX)){
                answer = effort;
                break;
            }
        }
        
        return answer;
    }
};