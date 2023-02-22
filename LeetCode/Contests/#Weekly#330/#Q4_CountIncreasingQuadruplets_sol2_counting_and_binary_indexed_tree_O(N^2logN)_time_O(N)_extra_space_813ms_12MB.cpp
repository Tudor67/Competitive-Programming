class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;

    int nonZeroLSB(int x){
        return x - ((x - 1) & x);
    }
    
public:
    BinaryIndexedTree(const int& N): N(N){
        tree.assign(N + 1, 0);
    }
    
    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += nonZeroLSB(i)){
            tree[i] += VAL;
        }
    }
    
    int query(const int& POS){
        int sum = 0;
        for(int i = POS; i >= 1; i -= nonZeroLSB(i)){
            sum += tree[i];
        }
        return sum;
    }
};

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        BinaryIndexedTree tree(N);
        for(int j = 0; j < N; ++j){
            long long ikPairs = 0;
            for(int l = j + 1; l < N; ++l){
                if(nums[j] < nums[l]){
                    res += ikPairs;
                }else{
                    ikPairs += tree.query(nums[l] - 1);
                }
            }
            tree.add(nums[j], 1);
        }
        
        return res;
    }
};