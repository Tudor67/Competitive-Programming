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
        return (row * COLS + col);
    }

public:
    int latestDayToCross(int ROWS, int COLS, vector<vector<int>>& cells) {
        const int MAX_INDEX = getIndex(ROWS - 1, COLS - 1, COLS);
        const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                   {0, -1}, {0, 1},
                                                   {1, -1}, {1, 0}, {1, 1}};

        DSU dsu(MAX_INDEX + 1);
        for(int row = 1; row < ROWS; ++row){
            int prevIndex = getIndex(row - 1, 0, COLS);
            int index = getIndex(row, 0, COLS);
            dsu.join(prevIndex, index);
            
            prevIndex = getIndex(row - 1, COLS - 1, COLS);
            index = getIndex(row, COLS - 1, COLS);
            dsu.join(prevIndex, index);
        }

        vector<bool> marked(MAX_INDEX + 1, false);
        for(int i = 0; i < (int)cells.size(); ++i){
            int row = cells[i][0] - 1;
            int col = cells[i][1] - 1;
            int index = getIndex(row, col, COLS);
            marked[index] = true;

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                int nextIndex = getIndex(nextRow, nextCol, COLS);
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && marked[nextIndex]){
                    dsu.join(index, nextIndex);
                }
            }

            int firstColIndex = getIndex(0, 0, COLS);
            int lastColIndex = getIndex(0, COLS - 1, COLS);
            if(dsu.find(firstColIndex) == dsu.find(lastColIndex)){
                return i;
            }
        }

        return cells.size();
    }
};