class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void init(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = NUMS[r];
        }else{
            int mid = (l + r) / 2;
            init(2 * node + 1, l, mid, NUMS);
            init(2 * node + 2, mid + 1, r, NUMS);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return INT_MAX;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const vector<int>& NUMS): N(NUMS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        init(0, 0, N - 1, NUMS);
    }
    
    int query(const int L, const int R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);

        long long res = TOTAL_SUM;
        
        SegmentTree tree(nums);
        for(long long ops = 1; ops < N; ++ops){
            long long cost = 0;
            for(int i = 0; i < N; ++i){
                if(i + ops < N){
                    cost += tree.query(i, i + ops);
                }else{
                    cost += min(tree.query(i, N - 1),
                                tree.query(0, (i + ops) % N));
                }
            }
            res = min(res, cost + ops * x);
        }
        
        return res;
    }
};