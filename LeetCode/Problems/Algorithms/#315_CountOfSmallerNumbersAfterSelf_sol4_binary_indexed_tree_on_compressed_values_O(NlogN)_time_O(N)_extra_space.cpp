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
        vector<int> count(N);
        
        // coordinate/value compression
        set<int> uniqueNums(nums.begin(), nums.end());
        unordered_map<int, int> originalToCompressed;
        int idx = 0;
        for(int num: uniqueNums){
            idx += 1;
            originalToCompressed[num] = idx;
        }
        
        // BinaryIndexedTree on compressed coordinates/values
        const int M = originalToCompressed.size();
        BinaryIndexedTree bitTree(M);
        for(int i = N - 1; i >= 0; --i){
            count[i] = bitTree.query(1, originalToCompressed[nums[i]] - 1);
            bitTree.add(originalToCompressed[nums[i]], 1);
        }
        
        return count;
    }
};