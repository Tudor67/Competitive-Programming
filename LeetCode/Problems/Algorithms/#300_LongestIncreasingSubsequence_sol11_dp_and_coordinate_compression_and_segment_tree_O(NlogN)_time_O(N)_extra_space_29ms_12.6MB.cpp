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
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        
        // coordinate compression of vector nums
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        const int U = v.size();
        unordered_map<int, int> originalToCompressed;
        for(int idx = 0; idx < U; ++idx){
            originalToCompressed[v[idx]] = idx;
        }
        
        // At step i:
        //    dp[i]: length of the longest strictly increasing subsequence ending with nums[i]
        //    segmentTree.query(L, R): max dp[k] such that
        //                             (0 <= k <= i - 1) and (L <= originalToCompressed[nums[k]] <= R)
        vector<int> dp(N);
        SegmentTree segmentTree(U);
        for(int i = 0; i < N; ++i){
            dp[i] = 1 + segmentTree.query(0, originalToCompressed[nums[i]] - 1);
            segmentTree.update(originalToCompressed[nums[i]], dp[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};