class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int N){
        rank.resize(N);
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
    int getIndex(int row, int col, const int COLS){
        return row * COLS + col;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        const int START_INDEX = getIndex(0, 0, COLS);
        const int END_INDEX = getIndex(ROWS - 1, COLS - 1, COLS);

        vector<tuple<int, int, int>> edges;
        edges.reserve(2 * ROWS * COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row + 1 < ROWS){
                    edges.push_back({abs(heights[row][col] - heights[row + 1][col]),
                                     getIndex(row, col, COLS), getIndex(row + 1, col, COLS)});
                }
                if(col + 1 < COLS){
                    edges.push_back({abs(heights[row][col] - heights[row][col + 1]),
                                     getIndex(row, col, COLS), getIndex(row, col + 1, COLS)});
                }
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(END_INDEX + 1);
        for(const tuple<int, int, int>& T: edges){
            int effort = get<0>(T);
            int index1 = get<1>(T);
            int index2 = get<2>(T);

            dsu.join(index1, index2);

            if(dsu.find(START_INDEX) == dsu.find(END_INDEX)){
                return effort;
            }
        }

        return 0;
    }
};