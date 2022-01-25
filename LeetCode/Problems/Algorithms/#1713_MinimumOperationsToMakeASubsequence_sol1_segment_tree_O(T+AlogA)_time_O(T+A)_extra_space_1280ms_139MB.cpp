class SegmentTree{
private:
    const int N;
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
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        const int T = target.size();
        const int A = arr.size();
        
        unordered_map<int, vector<int>> posOf;
        for(int i = 0; i < T; ++i){
            posOf[target[i]] = {};
        }
        
        for(int i = 0; i < A; ++i){
            if(posOf.count(arr[i])){
                posOf[arr[i]].push_back(i);
            }
        }
        
        SegmentTree segmentTree(A);
        for(int i = 0; i < T; ++i){
            for(int j = (int)posOf[target[i]].size() - 1; j >= 0; --j){
                int pos = posOf[target[i]][j];
                int maxLen = segmentTree.query(0, pos - 1);
                segmentTree.update(pos, maxLen + 1);
            }
        }
        
        return T - segmentTree.query(0, A - 1);
    }
};