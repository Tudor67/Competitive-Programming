class SegmentTree{
private:
    const int N;
    vector<int> tree;
    vector<int> lazy;

    void propagate(int node, int l, int r){
        tree[node] += lazy[node];
        if(l != r){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void add(int node, int l, int r, const int L, const int R, const int VAL){
        propagate(node, l, r);
        if(R < l || r < L){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] += VAL;
            propagate(node, l, r);
        }else{
            int mid = (l + r) / 2;
            add(2 * node + 1, l, mid, L, R, VAL);
            add(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getMax(int node, int l, int r, const int L, const int R){
        propagate(node, l, r);
        if(R < l || r < L){
            return 0;
        }else if(L <= l && r <= R){
            return tree[node];
        }else{
            int mid = (l + r) / 2;
            return max(getMax(2 * node + 1, l, mid, L, R),
                       getMax(2 * node + 2, mid + 1, r, L, R));
        }
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
        lazy.assign(2 * minLeaves, 0);
    }

    void add(const int L, const int R, const int VAL){
        if(L > R){
            return;
        }
        add(0, 0, N - 1, L, R, VAL);
    }

    int getMax(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getMax(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int Q = queries.size();

        int maxX = 0;
        for(vector<int>& query: queries){
            maxX = max(maxX, query[1]);
        }

        vector<bool> res;
        set<int> obstacles;
        SegmentTree tree(maxX + 1);
        for(int x = 0; x <= maxX; ++x){
            tree.add(x, x, maxX - x);
        }

        for(vector<int>& query: queries){
            if(query[0] == 1){
                int x = query[1];
                int xDist = tree.getMax(x, x);
                int leftObstacle = 0;
                if(!obstacles.empty() && *obstacles.begin() < x){
                    leftObstacle = *prev(obstacles.upper_bound(x));
                }
                tree.add(leftObstacle, x - 1, -xDist);
                obstacles.insert(x);
            }else{
                int x = query[1];
                int sz = query[2];
                if(tree.getMax(0, x - sz) >= sz){
                    res.push_back(true);
                }else{
                    res.push_back(false);
                }
            }
        }

        return res;
    }
};