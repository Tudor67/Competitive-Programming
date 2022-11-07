class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    static int gcd(int a, int b){
        while(a != 0 && b != 0){
            if(a > b){
                a %= b;
            }else{
                b %= a;
            }
        }
        return a + b;
    }
    
    void initTree(int node, int l, int r, const vector<int>& V){
        if(l == r){
            tree[node] = V[r];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, V);
            initTree(2 * node + 2, mid + 1, r, V);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return gcd(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const vector<int>& V): N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        initTree(0, 0, N - 1, V);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int upperBound(int firstPos, int lastPos, SegmentTree& tree, int k){
        int l = firstPos;
        int r = lastPos;
        while(l != r){
            int mid = (l + r) / 2;
            if(tree.query(firstPos, mid) < k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
    
    int lowerBound(int firstPos, int lastPos, SegmentTree& tree, int k){
        int l = firstPos;
        int r = lastPos;
        while(l != r){
            int mid = (l + r) / 2;
            if(tree.query(firstPos, mid) <= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
    
public:
    int subarrayGCD(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        SegmentTree tree(nums);
        for(int i = 0; i < N; ++i){
            res += upperBound(i, N, tree, k) - lowerBound(i, N, tree, k);
        }
        
        return res;
    }
};