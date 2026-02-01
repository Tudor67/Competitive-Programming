class SegmentTree{
private:
    const int N;
    const int INF;
    vector<int> tree;

    void minimize(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = min(tree[node], VAL);
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                minimize(2 * node + 1, l, mid, POS, VAL);
            }else{
                minimize(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getMin(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return INF;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(getMin(2 * node + 1, l, mid, L, R),
                   getMin(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N, const int INF): N(N), INF(INF){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, INF);
    }

    void minimize(const int POS, const int VAL){
        minimize(0, 0, N - 1, POS, VAL);
    }

    int getMin(const int L, const int R){
        if(L <= R){
            return getMin(0, 0, N - 1, L, R);
        }
        return INF;
    }
};

class Solution {
private:
    void minimize(int& a, int b){
        a = min(a, b);
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        // dp[t][row][col]: min cost to reach cell (row, col)
        //                  using at most t teleports
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(ROWS, vector<int>(COLS, INF)));
        dp[0][0][0] = 0;

        int maxVal = grid[0][0];
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                maxVal = max(maxVal, grid[row][col]);
            }
        }

        vector<SegmentTree> trees;
        trees.reserve(k + 1);
        for(int t = 0; t <= k; ++t){
            trees.emplace_back(maxVal + 1, INF);
        }
        
        trees[0].minimize(grid[0][0], 0);

        for(int t = 0; t <= k; ++t){
            for(int row = 0; row < ROWS; ++row){
                for(int col = 0; col < COLS; ++col){
                    if(row - 1 >= 0){
                        minimize(dp[t][row][col], dp[t][row - 1][col] + grid[row][col]);
                    }

                    if(col - 1 >= 0){
                        minimize(dp[t][row][col], dp[t][row][col - 1] + grid[row][col]);
                    }
                    
                    if(t >= 1){
                        minimize(dp[t][row][col], trees[t - 1].getMin(grid[row][col], maxVal));
                    }

                    trees[t].minimize(grid[row][col], dp[t][row][col]);
                }
            }
        }

        return dp[k][ROWS - 1][COLS - 1];
    }
};