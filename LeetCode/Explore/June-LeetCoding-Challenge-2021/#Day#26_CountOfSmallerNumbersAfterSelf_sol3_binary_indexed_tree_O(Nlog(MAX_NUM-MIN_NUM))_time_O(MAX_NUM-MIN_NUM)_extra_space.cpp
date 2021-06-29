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
        tree.resize(N + 1, 0);
    }
    
    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += nonZeroLSB(i)){
            tree[i] += VAL;
        }
    }
    
    int query(const int& L, const int& R){
        if(L <= R){
            return query(R) - query(L - 1);
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> count(N);
        BinaryIndexedTree bitTree(MAX_NUM - MIN_NUM + 1);
        for(int i = N - 1; i >= 0; --i){
            count[i] = bitTree.query(1, nums[i] - MIN_NUM);
            bitTree.add(nums[i] + 1 - MIN_NUM, 1);
        }
        
        return count;
    }
};