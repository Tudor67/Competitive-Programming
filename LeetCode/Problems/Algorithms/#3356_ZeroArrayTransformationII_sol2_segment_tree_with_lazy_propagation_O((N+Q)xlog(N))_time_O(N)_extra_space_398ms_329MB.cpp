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
            return;
        }
        if(L <= l && r <= R){
            lazy[node] += VAL;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        add(2 * node + 1, l, mid, L, R, VAL);
        add(2 * node + 2, mid + 1, r, L, R, VAL);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(const int N): N(N) {
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
        lazy.assign(2 * minLeaves, 0);
    }

    void add(const int L, const int R, const int VAL){
        if(L <= R){
            add(0, 0, N - 1, L, R, VAL);
        }
    }

    int getMax(){
        return tree[0];
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        SegmentTree tree(N);
        for(int i = 0; i < N; ++i){
            tree.add(i, i, nums[i]);
        }

        if(tree.getMax() <= 0){
            return 0;
        }

        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            tree.add(l, r, -val);

            if(tree.getMax() <= 0){
                return i + 1;
            }
        }

        return -1;
    }
};