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
        
        int maxCoordinate = 0;
        for(int i = 0; i < N; ++i){
            maxCoordinate = max(intervals[i][1], maxCoordinate);
        }
        
        for(int i = 0; i < Q; ++i){
            maxCoordinate = max(queries[i], maxCoordinate);
        }
        
        SegmentTree segmentTree(maxCoordinate + 1, INF);
        for(int i = 0; i < N; ++i){
            int l = intervals[i][0];
            int r = intervals[i][1];
            segmentTree.update(l, r, r - l + 1);
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = segmentTree.query(queries[i]);
            if(answer[i] == INF){
                answer[i] = -1;
            }
        }
        
        return answer;
    }
};