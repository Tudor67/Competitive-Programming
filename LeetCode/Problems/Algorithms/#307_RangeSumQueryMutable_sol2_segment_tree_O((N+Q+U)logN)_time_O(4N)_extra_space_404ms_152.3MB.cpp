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
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
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
    SegmentTree(const vector<int>& NUMS): N((int)NUMS.size()){
        tree.resize(4 * N + 10);
        init(0, 0, N - 1, NUMS);
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

class NumArray {
private:
    SegmentTree segmentTree;
    
public:
    NumArray(vector<int>& nums): segmentTree(nums) {
        
    }
    
    void update(int index, int val) {
        segmentTree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return segmentTree.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */