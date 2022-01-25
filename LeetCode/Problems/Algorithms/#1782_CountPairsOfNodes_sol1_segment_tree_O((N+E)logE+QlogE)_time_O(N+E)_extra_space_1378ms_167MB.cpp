class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void add(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
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
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void add(const int& POS, const int& VAL){
        add(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> countPairs(int N, vector<vector<int>>& edges, vector<int>& queries) {
        vector<vector<int>> g(N);
        vector<int> initialDegree(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0] - 1;
            int y = EDGE[1] - 1;
            if(x < y){
                g[x].push_back(y);
            }else{
                g[y].push_back(x);
            }
            initialDegree[x] += 1;
            initialDegree[y] += 1;
        }
        
        const int MAX_DEGREE = *max_element(initialDegree.begin(), initialDegree.end());
        const int Q = queries.size();
        vector<int> answer(Q);
        
        SegmentTree segmentTree(MAX_DEGREE + 1);
        vector<int> degree = initialDegree;
        vector<bool> updated(N, false);
        
        for(int x = 0; x < N; ++x){
            segmentTree.add(degree[x], 1);
        }
        
        for(int x = 0; x < N; ++x){
            for(int y: g[x]){
                degree[y] -= 1;
            }
            
            for(int y: g[x]){
                if(!updated[y]){
                    segmentTree.add(initialDegree[y], -1);
                    segmentTree.add(degree[y], 1);
                    updated[y] = true;
                }
            }
            
            segmentTree.add(degree[x], -1);
            for(int i = 0; i < Q; ++i){
                answer[i] += segmentTree.query(max(0, queries[i] - degree[x] + 1), MAX_DEGREE);
            }
            
            for(int y: g[x]){
                if(updated[y]){
                    segmentTree.add(degree[y], -1);
                    segmentTree.add(initialDegree[y], 1);
                    degree[y] = initialDegree[y];
                    updated[y] = false;
                }
            }
        }
        
        return answer;
    }
};