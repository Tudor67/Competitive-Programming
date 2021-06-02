class SegmentTree{
private:
    const int N;
    vector<int> tree;
    vector<int> lazy;
    
    void propagate(int node){
        if(2 * node + 2 < (int)lazy.size()){
            lazy[2 * node + 1] = max(lazy[node], lazy[2 * node + 1]);
            lazy[2 * node + 2] = max(lazy[node], lazy[2 * node + 2]);
        }
        lazy[node] = 0;
    }
    
    void update(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            return;
        }
        if(L <= l && r <= R){
            tree[node] = VAL;
            lazy[node] = VAL;
            propagate(node);
            return;
        }
        propagate(node);
        int mid = (l + r) / 2;
        update(2 * node + 1, l, mid, L, R, VAL);
        update(2 * node + 2, mid + 1, r, L, R, VAL);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            tree[node] = max(lazy[node], tree[node]);
            propagate(node);
            return tree[node];
        }
        propagate(node);
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
        tree.resize(2 * minLeaves, 0);
        lazy.resize(2 * minLeaves, 0);
    }
    
    void update(const int& L, const int& R, const int& VAL){
        if(L > R){
            return;
        }
        update(0, 0, N - 1, L, R, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return -1;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        const int N = positions.size();
        
        // Step 1: value compression for positions
        vector<int> v(2 * N);
        for(int i = 0; i < N; ++i){
            int leftPos = positions[i][0];
            int rightPos = positions[i][0] + positions[i][1] - 1;
            v[i] = leftPos;
            v[i + N] = rightPos;
        }
        
        sort(v.begin(), v.end());
        
        map<int, int> compressedValue;
        int idx = 0;
        compressedValue[v[0]] = 0;
        for(int i = 1; i < 2 * N; ++i){
            if(v[i - 1] != v[i]){
                idx += 1;
                compressedValue[v[i]] = idx;
            }
        }
        
        // Step 2: segment tree (with lazy propagation) on compressed values
        const int M = compressedValue.size();
        SegmentTree segmentTree(M);
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            int leftPos = positions[i][0];
            int rightPos = positions[i][0] + positions[i][1] - 1;
            int sideLength = positions[i][1];
            int maxHeight = sideLength + segmentTree.query(compressedValue[leftPos], compressedValue[rightPos]);
            segmentTree.update(compressedValue[leftPos], compressedValue[rightPos], maxHeight);
            answer[i] = segmentTree.query(0, M - 1);
        }
        
        return answer;
    }
};