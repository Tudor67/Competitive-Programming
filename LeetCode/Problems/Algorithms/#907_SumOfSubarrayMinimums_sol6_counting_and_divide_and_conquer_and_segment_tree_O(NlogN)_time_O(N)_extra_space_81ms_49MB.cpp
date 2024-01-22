class SegmentTree{
private:
    const int N;
    vector<pair<int, int>> tree;

    void buildTree(int node, int l, int r, const vector<int>& ARR){
        if(l == r){
            tree[node] = {ARR[r], r};
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, ARR);
            buildTree(2 * node + 2, mid + 1, r, ARR);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    pair<int, int> getMin(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return {INT_MAX, INT_MAX};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(getMin(2 * node + 1, l, mid, L, R),
                   getMin(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<int>& ARR): N(ARR.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, ARR);
    }

    int getIdxOfMin(const int L, const int R){
        if(L > R){
            return -1;
        }
        return getMin(0, 0, N - 1, L, R).second;
    }
};

class Solution {
private:
    const int MODULO = 1e9 + 7;

    void solve(const int L, const int R, vector<int>& arr, SegmentTree& segmentTree, int& res){
        if(L > R){
            return;
        }

        int idxOfMin = segmentTree.getIdxOfMin(L, R);

        long long leftCount = idxOfMin - L + 1;
        long long rightCount = R - idxOfMin + 1;
        long long fixedMin = arr[idxOfMin];
        long long contrib = (leftCount * rightCount % MODULO) * fixedMin % MODULO;

        res = (res + contrib) % MODULO;

        solve(L, idxOfMin - 1, arr, segmentTree, res);
        solve(idxOfMin + 1, R, arr, segmentTree, res);
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        const int N = arr.size();

        int res = 0;
        SegmentTree segmentTree(arr);
        solve(0, N - 1, arr, segmentTree, res);

        return res;
    }
};