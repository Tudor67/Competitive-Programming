class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;
    
    static int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }
    
    int query(const int& POS){
        int sum = 0;
        for(int i = POS; i >= 1; i -= nonZeroLSB(i)){
            sum += tree[i];
        }
        return sum;
    }
    
public:
    BinaryIndexedTree(const int& N): N(N){
        tree.resize(N + 1);
    }
    
    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += nonZeroLSB(i)){
            tree[i] += VAL;
        }
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(R) - query(L - 1);
    }
};

class NumArray {
private:
    BinaryIndexedTree tree;
    
public:
    NumArray(vector<int>& nums): tree((int)nums.size()) {
        for(int i = 0; i < (int)nums.size(); ++i){
            tree.add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int oldVal = tree.query(index + 1, index + 1);
        tree.add(index + 1, val - oldVal);
    }
    
    int sumRange(int left, int right) {
        return tree.query(left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */