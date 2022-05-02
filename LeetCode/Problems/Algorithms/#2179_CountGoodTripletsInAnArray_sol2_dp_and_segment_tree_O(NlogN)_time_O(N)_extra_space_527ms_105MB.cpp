class SegmentTree{
private:
    const int N;
    vector<long long> tree;
    
    void add(int node, int l, int r, const int& POS, const long long& VAL){
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
    
    long long query(int node, int l, int r, const int& L, const int& R){
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
    
    void reset(){
        fill(tree.begin(), tree.end(), 0);
    }
    
    void add(const int& POS, const long long& VAL){
        add(0, 0, N - 1, POS, VAL);
    }
    
    long long query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        
        vector<int> posOf(N);
        for(int i = 0; i < N; ++i){
            posOf[nums1[i]] = i;
        }
        
        vector<int> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = posOf[nums2[i]];
        }
        
        // dp[k][i]: number of tuples (pos1, pos2, ..., pos[k - 1], i) of size k in v[0 .. i]
        //           such that (pos1 < pos2 < ... < pos[k - 1] < i) and
        //                     (v[pos1] < v[pos2] < ... < v[pos[k - 1]] < v[i])
        vector<vector<long long>> dp(4, vector<long long>(N));
        SegmentTree segmentTree(N);
        fill(dp[1].begin(), dp[1].end(), 1);
        for(int k = 2; k <= 3; ++k){
            segmentTree.reset();
            for(int i = 0; i < N; ++i){
                dp[k][i] = segmentTree.query(0, v[i] - 1);
                segmentTree.add(v[i], dp[k - 1][i]);
            }
        }
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += dp[3][i];
        }
        
        return res;
    }
};