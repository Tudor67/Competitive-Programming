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
        if(R < l || r < L){
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
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        SegmentTree tree(N + 1);
        for(int j = 0; j < N; ++j){
            long long ikPairs = 0;
            for(int l = j + 1; l < N; ++l){
                if(nums[j] < nums[l]){
                    res += ikPairs;
                }else{
                    ikPairs += tree.query(0, nums[l] - 1);
                }
            }
            tree.add(nums[j], 1);
        }
        
        return res;
    }
};