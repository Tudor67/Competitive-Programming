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
                update(2 * node, l, mid, POS, VAL);
            }else{
                update(2 * node + 1, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
        return max(query(2 * node, l, mid, L, R),
                   query(2 * node + 1, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& MAX_VAL): N(MAX_VAL){
        tree.resize(4 * N + 10, 0);
    }
    
    void update(const int& POS, const int& VAL){
        update(1, 1, N, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(1, 1, N, L, R);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        
        // value compression
        vector<int> numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());
        
        map<int, int> compressedValue;
        int idx = 1;
        compressedValue[numsSorted[0]] = idx;
        for(int i = 1; i < N; ++i){
            if(numsSorted[i - 1] != numsSorted[i]){
                idx += 1;
                compressedValue[numsSorted[i]] = idx;
            }
        }
        
        // segment tree on compressed values
        // tree.query(1, compressedValue[nums[i]]): max length of a strictly increasing subsequence with last element nums[i]
        const int M = idx;
        SegmentTree tree(M);
        for(int num: nums){
            int maxLen = 1 + tree.query(1, compressedValue[num] - 1);
            tree.update(compressedValue[num], maxLen);
        }
        
        return tree.query(1, M);
    }
};