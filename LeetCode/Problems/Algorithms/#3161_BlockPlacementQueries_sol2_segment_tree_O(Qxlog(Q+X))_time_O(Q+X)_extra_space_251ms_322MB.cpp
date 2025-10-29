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

        int maxX = 0;
        for(vector<int>& query: queries){
            maxX = max(maxX, query[1]);
        }

        vector<bool> res;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(maxX + 1);

        SegmentTree tree(maxX + 2);
        tree.update(0, maxX + 1);

        for(vector<int>& query: queries){
            if(query[0] == 1){
                int x = query[1];
                int leftObstacle = *prev(obstacles.upper_bound(x));
                int rightObstacle = *obstacles.upper_bound(x);
                tree.update(leftObstacle, x - leftObstacle);
                tree.update(x, rightObstacle - x);
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