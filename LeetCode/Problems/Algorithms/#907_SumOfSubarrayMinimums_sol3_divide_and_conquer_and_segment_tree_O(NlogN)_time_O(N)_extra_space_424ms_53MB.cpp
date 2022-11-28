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
    
    pair<int, int> query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return {INT_MAX, INT_MIN};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
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
    
    int getPosOfMin(const int& L, const int& R){
        return query(0, 0, N - 1, L, R).second;
    }
};

class Solution {
private:
    long long solve(vector<int>& arr, const int& L, const int& R, SegmentTree& tree, const long long& MODULO){
        if(L > R){
            return 0;
        }
        long long posOfMin = tree.getPosOfMin(L, R);
        long long contrib = (posOfMin - L + 1) * (R - posOfMin + 1) * arr[posOfMin];
        long long leftContrib = solve(arr, L, posOfMin - 1, tree, MODULO);
        long long rightContrib = solve(arr, posOfMin + 1, R, tree, MODULO);
        return (contrib + leftContrib + rightContrib) % MODULO;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MODULO = 1e9 + 7;
        const int N = arr.size();
        SegmentTree tree(arr);
        return solve(arr, 0, N - 1, tree, MODULO);
    }
};