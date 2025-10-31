class SegmentTree{
private:
    const int N;
    vector<pair<int, int>> tree;

    void init(int node, int l, int r, const vector<int>& VALUES){
        if(l == r){
            tree[node] = {VALUES[r], r};
        }else{
            int mid = (l + r) / 2;
            init(2 * node + 1, l, mid, VALUES);
            init(2 * node + 2, mid + 1, r, VALUES);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    pair<int, int> getMinWithIndex(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return {INT_MAX, INT_MAX};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(getMinWithIndex(2 * node + 1, l, mid, L, R),
                   getMinWithIndex(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<int>& VALUES): N(VALUES.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, {0, 0});
        init(0, 0, N - 1, VALUES);
    }

    pair<int, int> getMinWithIndex(const int L, const int R){
        if(L > R){
            return {INT_MAX, INT_MAX};
        }
        return getMinWithIndex(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int computeMinOps(const int L, const int R, int prevMinVal, SegmentTree& tree){
        if(L > R){
            return 0;
        }
        auto [minVal, indexOfMinVal] = tree.getMinWithIndex(L, R);
        return minVal - prevMinVal +
               computeMinOps(L, indexOfMinVal - 1, minVal, tree) +
               computeMinOps(indexOfMinVal + 1, R, minVal, tree);
    }

public:
    int minNumberOperations(vector<int>& target) {
        const int N = target.size();
        SegmentTree tree(target);
        return computeMinOps(0, N - 1, 0, tree);
    }
};