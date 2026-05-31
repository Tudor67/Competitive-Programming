class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getMax(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(getMax(2 * node + 1, l, mid, L, R),
                   getMax(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
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
        const int M = 50'000;

        SegmentTree tree(M + 2);
        tree.update(0, M + 1);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(M + 1);

        vector<bool> res;
        for(const vector<int>& QUERY: queries){
            int queryType = QUERY[0];
            int x = QUERY[1];
            if(queryType == 1){
                auto it = obstacles.upper_bound(x);
                int prevObstacle = *prev(it);
                int nextObstacle = *it;
                tree.update(prevObstacle, x - prevObstacle);
                tree.update(x, nextObstacle - x);
                obstacles.insert(x);
            }else{
                int sz = QUERY[2];
                res.push_back(tree.getMax(0, x - sz) >= sz);
            }
        }

        return res;
    }
};