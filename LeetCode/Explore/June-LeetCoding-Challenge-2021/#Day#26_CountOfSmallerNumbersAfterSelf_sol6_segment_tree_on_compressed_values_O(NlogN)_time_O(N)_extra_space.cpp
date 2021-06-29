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
        tree.resize(2 * minLeaves, 0);
    }
    
    void add(const int& POS, const int& VAL){
        add(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L <= R){
            return query(0, 0, N - 1, L, R);
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        vector<int> count(N);
        
        // coordinate/value compression
        set<int> uniqueNums(nums.begin(), nums.end());
        unordered_map<int, int> originalToCompressed;
        int idx = -1;
        for(int num: uniqueNums){
            idx += 1;
            originalToCompressed[num] = idx;
        }
        
        // segment tree on compressed coordinates/values
        const int M = originalToCompressed.size();
        SegmentTree segmentTree(M);
        for(int i = N - 1; i >= 0; --i){
            count[i] = segmentTree.query(0, originalToCompressed[nums[i]] - 1);
            segmentTree.add(originalToCompressed[nums[i]], 1);
        }
        
        return count;
    }
};