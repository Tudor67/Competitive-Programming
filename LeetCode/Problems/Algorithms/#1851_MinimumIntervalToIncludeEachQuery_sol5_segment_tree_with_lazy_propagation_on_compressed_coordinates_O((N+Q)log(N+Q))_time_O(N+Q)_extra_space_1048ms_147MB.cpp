class SegmentTree{
private:
    const int N;
    const int IDENTITY_ELEMENT;
    vector<int> tree;
    vector<int> lazy;
    
    void propagate(int node){
        if(2 * node + 2 < (int)lazy.size()){
            lazy[2 * node + 1] = min(lazy[node], lazy[2 * node + 1]);
            lazy[2 * node + 2] = min(lazy[node], lazy[2 * node + 2]);
        }
        lazy[node] = IDENTITY_ELEMENT;
    }
    
    void update(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] = min(VAL, lazy[node]);
            tree[node] = min(lazy[node], tree[node]);
            propagate(node);
        }else{
            propagate(node);
            int mid = (l + r) / 2;
            update(2 * node + 1, l, mid, L, R, VAL);
            update(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& POS){
        if(l == r){
            tree[node] = min(lazy[node], tree[node]);
            return tree[node];
        }        
        propagate(node);
        int mid = (l + r) / 2;
        if(POS <= mid){
            return query(2 * node + 1, l, mid, POS);
        }
        return query(2 * node + 2, mid + 1, r, POS);
    }
    
public:
    SegmentTree(const int& N, const int& IDENTITY_ELEMENT): N(N), IDENTITY_ELEMENT(IDENTITY_ELEMENT){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, IDENTITY_ELEMENT);
        lazy.resize(2 * minLeaves, IDENTITY_ELEMENT);
    }
    
    void update(const int& L, const int& R, const int& VAL){
        update(0, 0, N - 1, L, R, VAL);
    }
    
    int query(const int& POS){
        return query(0, 0, N - 1, POS);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int N = intervals.size();
        const int Q = queries.size();
        const int INF = INT_MAX;
        
         // coordinate compression
        vector<int> coordinates(2 * N + Q);
        for(int i = 0; i < N; ++i){
            coordinates[i] = intervals[i][0];
            coordinates[i + N] = intervals[i][1];
        }
        
        for(int i = 0; i < Q; ++i){
            coordinates[i + 2 * N] = queries[i];
        }
        
        sort(coordinates.begin(), coordinates.end());
        
        unordered_map<int, int> originalToCompressed;
        int idx = 0;
        originalToCompressed[coordinates[0]] = 0;
        for(int i = 1; i < 2 * N + Q; ++i){
            if(coordinates[i] != coordinates[i - 1]){
                idx += 1;
                originalToCompressed[coordinates[i]] = idx;
            }
        }
        
        const int C = idx + 1;
        
        // segment tree with lazy propagation (on compressed coordinates)
        SegmentTree segmentTree(C, INF);
        for(int i = 0; i < N; ++i){
            int l = originalToCompressed[intervals[i][0]];
            int r = originalToCompressed[intervals[i][1]];
            int len = intervals[i][1] - intervals[i][0] + 1;
            segmentTree.update(l, r, len);
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = segmentTree.query(originalToCompressed[queries[i]]);
            if(answer[i] == INF){
                answer[i] = -1;
            }
        }
        
        return answer;
    }
};