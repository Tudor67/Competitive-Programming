class SegmentTree{
private:
    const int N;
    vector<long long> tree;
    
    void update(int node, int l, int r, const int POS, const long long VAL){
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
    
    long long query(int node, int l, int r, const int L, const int R){
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
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int POS, const long long VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    long long query(const int L, const int R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> diffs(N);
        for(int i = 0; i < N; ++i){
            diffs[i] = nums[i] - i;
        }
        
        vector<int> sortedDiffs = diffs;
        sort(sortedDiffs.begin(), sortedDiffs.end());
        sortedDiffs.resize(unique(sortedDiffs.begin(), sortedDiffs.end()) - sortedDiffs.begin());
        
        long long res = nums[0];
        SegmentTree tree(sortedDiffs.size());
        
        for(int i = 0; i < N; ++i){
            int compressedDiff = lower_bound(sortedDiffs.begin(), sortedDiffs.end(), diffs[i])
                                 - sortedDiffs.begin();
            long long maxSum = max((long long)0, tree.query(0, compressedDiff)) + nums[i];
            tree.update(compressedDiff, maxSum);
            res = max(res, maxSum);
        }
        
        return res;
    }
};