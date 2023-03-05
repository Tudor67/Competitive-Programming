class LazySegmentTree{
private:
    const int N;
    vector<int> flip;
    vector<int> tree;
    
    void buildTree(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = NUMS[l];
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, NUMS);
            buildTree(2 * node + 2, mid + 1, r, NUMS);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    void propagate(int node, int l, int r){
        if(l == r){
            // is leaf
            tree[node] ^= flip[node];
            flip[node] = 0;
        }else{
            // is not leaf
            if(flip[node]){
                tree[node] = (r - l + 1) - tree[node];
            }
            flip[2 * node + 1] ^= flip[node];
            flip[2 * node + 2] ^= flip[node];
            flip[node] = 0;
        }
    }
    
    void flipUpdate(int node, int l, int r, const int& L, const int& R){
        propagate(node, l, r);
        if(r < L || R < l){
            return;
        }else if(L <= l && r <= R){
            flip[node] ^= 1;
            propagate(node, l, r);
        }else{
            int mid = (l + r) / 2;
            flipUpdate(2 * node + 1, l, mid, L, R);
            flipUpdate(2 * node + 2, mid + 1, r, L, R);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
public:
    LazySegmentTree(const vector<int>& NUMS): N(NUMS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        flip.assign(2 * minLeaves, 0);
        tree.assign(2 * minLeaves, 0);
        buildTree(0, 0, N - 1, NUMS);
    }
    
    int queryAll(){
        propagate(0, 0, N - 1);
        return tree[0];
    }
    
    void flipUpdate(const int& L, const int& R){
        if(L <= R){
            flipUpdate(0, 0, N - 1, L, R);
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const int N = nums1.size();
        const int Q = queries.size();
        
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        
        vector<long long> res;
        LazySegmentTree tree(nums1);
        
        for(int i = 0; i < Q; ++i){
            if(queries[i][0] == 1){
                int l = queries[i][1];
                int r = queries[i][2];
                tree.flipUpdate(l, r);
                sum1 = tree.queryAll();
            }else if(queries[i][0] == 2){
                long long p = queries[i][1];
                sum2 += sum1 * p;
            }else{
                res.push_back(sum2);
            }
        }
        
        return res;
    }
};