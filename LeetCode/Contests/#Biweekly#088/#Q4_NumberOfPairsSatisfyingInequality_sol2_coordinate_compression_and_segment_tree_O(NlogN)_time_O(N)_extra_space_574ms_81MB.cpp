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
    
    int getSum(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return getSum(2 * node + 1, l, mid, L, R) +
               getSum(2 * node + 2, mid + 1, r, L, R);
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
    
    int getSum(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return getSum(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        const int N = nums1.size();
        
        // coordinate compression
        vector<int> v(2 * N);
        for(int i = 0; i < N; ++i){
            v[i] = nums1[i] - nums2[i];
            v[i + N] = nums1[i] - nums2[i] + diff;
        }
        
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        // segment tree
        const int U = v.size();
        SegmentTree tree(U);
        long long res = 0;
        for(int i = N - 1; i >= 0; --i){
            int pos = lower_bound(v.begin(), v.end(), nums1[i] - nums2[i]) - v.begin();
            res += tree.getSum(pos, U - 1);
            
            pos = lower_bound(v.begin(), v.end(), nums1[i] - nums2[i] + diff) - v.begin();
            tree.add(pos, 1);
        }
        
        return res;
    }
};