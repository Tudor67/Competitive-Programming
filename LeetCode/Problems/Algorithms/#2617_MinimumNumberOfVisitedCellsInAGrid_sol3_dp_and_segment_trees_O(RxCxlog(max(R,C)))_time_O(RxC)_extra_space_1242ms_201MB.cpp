class SegmentTree{
private:
    const int N;
    const int INF;
    vector<int> tree;

    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return INF;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N, const int INF): N(N), INF(INF){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, INF);
    }

    void reset(){
        fill(tree.begin(), tree.end(), INF);
    }

    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int& L, const int& R){
        if(L > R){
            return INF;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        vector<SegmentTree> availAtCol(COLS, SegmentTree(ROWS, INF));
        SegmentTree availAtCurrentRow(COLS, INF);
        dist[ROWS - 1][COLS - 1] = 1;
        
        for(int row = ROWS - 1; row >= 0; --row){
            availAtCurrentRow.reset();
            for(int col = COLS - 1; col >= 0; --col){
                dist[row][col] = min(dist[row][col], 1 + availAtCol[col].query(row + 1, min(ROWS - 1, row + grid[row][col])));
                dist[row][col] = min(dist[row][col], 1 + availAtCurrentRow.query(col + 1, min(COLS - 1, col + grid[row][col])));
                availAtCol[col].update(row, dist[row][col]);
                availAtCurrentRow.update(col, dist[row][col]);
            }
        }

        if(dist[0][0] == INF){
            return -1;
        }
        return dist[0][0];
    }
};