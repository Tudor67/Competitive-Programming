class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void maxUpdate(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = max(tree[node], VAL);
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                maxUpdate(2 * node + 1, l, mid, POS, VAL);
            }else{
                maxUpdate(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int maxQuery(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return -1;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(maxQuery(2 * node + 1, l, mid, L, R),
                   maxQuery(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, -1);
    }
    
    void maxUpdate(const int POS, const int VAL){
        maxUpdate(0, 0, N - 1, POS, VAL);
    }
    
    int maxQuery(const int L, const int R){
        if(L > R){
            return -1;
        }
        return maxQuery(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const int N = nums1.size();
        const int Q = queries.size();
        
        // sort cells (nums1[i], nums2[i]) in decreasing order of nums2[i]
        vector<pair<int, int>> c(N);
        for(int i = 0; i < N; ++i){
            c[i] = {nums1[i], nums2[i]};
        }
        
        sort(c.begin(), c.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 return LHS.second > RHS.second;
             });
        
        // coordinate compression
        vector<int> v = nums1;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        // segment tree on compressed values
        const int V_SIZE = v.size();
        SegmentTree tree(V_SIZE);
        
        // sort queries in decreasing order of x2 coordinate
        vector<int> p(Q);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return queries[lhs][1] > queries[rhs][1];
            });
        
        // sweep line
        // process queries in decreasing order of x2 coordinate using a segment tree on compressed values
        vector<int> res(Q);
        int cIdx = 0;
        for(int qIdx: p){
            int q1 = queries[qIdx][0];
            int q2 = queries[qIdx][1];
            
            while(cIdx < N && q2 <= c[cIdx].second){
                int compressedIdx = lower_bound(v.begin(), v.end(), c[cIdx].first) - v.begin();
                tree.maxUpdate(compressedIdx, c[cIdx].first + c[cIdx].second);
                cIdx += 1;
            }
            
            int compressedIdxQ1 = lower_bound(v.begin(), v.end(), q1) - v.begin();
            res[qIdx] = tree.maxQuery(compressedIdxQ1, V_SIZE - 1);
        }
        
        return res;
    }
};