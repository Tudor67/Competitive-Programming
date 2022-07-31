class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;
    
    int lsb1(int x){
        return x - (x & (x - 1));
    }
    
    void add(int pos, int val){
        for(int i = pos + 1; i <= N; i += lsb1(i)){
            tree[i] += val;
        }
    }
    
    int query(int pos){
        int sum = 0;
        for(int i = pos + 1; i >= 1; i -= lsb1(i)){
            sum += tree[i];
        }
        return sum;
    }
    
public:
    BinaryIndexedTree(const vector<int>& NUMS): N(NUMS.size()){
        tree.resize(N + 1);
        for(int i = 0; i < N; ++i){
            tree[i + 1] += NUMS[i];
            if(i + 1 + lsb1(i + 1) <= N){
                tree[i + 1 + lsb1(i + 1)] += tree[i + 1];
            }
        }
    }
    
    void update(int pos, int val){
        int oldVal = query(pos, pos);
        add(pos, val - oldVal);
    }
    
    int query(const int& L, const int& R){
        return query(R) - query(L - 1);
    }
};

class NumArray {
private:
    BinaryIndexedTree tree;
    
public:
    NumArray(vector<int>& nums): tree(nums) {
        
    }
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */