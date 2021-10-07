class SegmentTree{
private:
    const int INF = 1e9;
    const int N;
    const vector<int>& V;
    vector<int> tree;
    
    int valAt(int idx){
        if(idx == INF){
            return INF;
        }
        return V[idx];
    }
    
    int getIdxOfMin(int firstIdx, int secondIdx){
        if(valAt(firstIdx) <= valAt(secondIdx)){
            return firstIdx;
        }
        return secondIdx;
    }
    
    void buildTree(int node, int l, int r){
        if(l == r){
            tree[node] = r;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid);
            buildTree(2 * node + 2, mid + 1, r);
            tree[node] = getIdxOfMin(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return INF;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return getIdxOfMin(query(2 * node + 1, l, mid, L, R),
                           query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(vector<int>& V): V(V), N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, INF);
        buildTree(0, 0, N - 1);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    void solve(const int& L, const int& R, vector<int>& nums, vector<long long>& prefixSum, SegmentTree& segmentTree, long long& maxProduct){
        if(L <= R){
            const int MIN_NUM_POS = segmentTree.query(L, R);
            const int MIN_NUM = nums[MIN_NUM_POS];
            const long long SUM = prefixSum[R] - (L >= 1 ? prefixSum[L - 1] : 0);
            
            long long product = MIN_NUM * SUM;
            maxProduct = max(product, maxProduct);
            
            solve(L, MIN_NUM_POS - 1, nums, prefixSum, segmentTree, maxProduct);
            solve(MIN_NUM_POS + 1, R, nums, prefixSum, segmentTree, maxProduct);
        }
    }
    
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        SegmentTree segmentTree(nums);
        vector<long long> prefixSum(N);
        prefixSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        long long maxProduct = 0;
        solve(0, N - 1, nums, prefixSum, segmentTree, maxProduct);
        
        return maxProduct % MODULO;
    }
};

/*
   Recursive solution (using segment tree and prefix sums)
   Time complexity: O(NlogN), N = nums.size()
   Extra-Space complexity: O(N), N = nums.size()
   
   Goal: maximize product = sumOfRange * minOfRange;
   Bottleneck: minOfRange;
   For a given range [L, R]:
       1.) compute minOfRange using a segment tree (O(logN) operation);
       2.) compute sumOfRange using a precomputed prefix sum vector (O(1) operation);
       3.) compute product = sumOfRange * minOfRange;
       4.) update maxProduct;
       5.) recursively solve the range [L, minOfRangePos - 1] and [minOfRangePos + 1, R];
       
   Details: the segment tree keeps in nodes indices/positions of minimum (not minimum itself);
*/