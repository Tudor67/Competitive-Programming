class SegmentTree{
private:
    const int N;
    vector<int> a;
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            a[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            a[node] = max(a[2 * node + 1], a[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return a[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& N): N(N){
        a.resize(4 * N + 10, 0);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N, L, R);
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int MAX_VAL = *max_element(nums.begin(), nums.end());
        SegmentTree maxDecTree(MAX_VAL);
        SegmentTree maxIncTree(MAX_VAL);
        for(int num: nums){
            int maxDec = 1 + maxIncTree.query(num + 1, MAX_VAL);
            int maxInc = 1 + maxDecTree.query(0, num - 1);
            maxDecTree.update(num, maxDec);
            maxIncTree.update(num, maxInc);
        }
        return max(maxDecTree.query(0, MAX_VAL), maxIncTree.query(0, MAX_VAL));
    }
};