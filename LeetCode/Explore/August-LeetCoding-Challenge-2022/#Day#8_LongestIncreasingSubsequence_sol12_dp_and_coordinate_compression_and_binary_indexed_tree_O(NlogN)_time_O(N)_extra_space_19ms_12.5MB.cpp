class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;
    
    int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }
    
public:
    BinaryIndexedTree(const int& N): N(N){
        tree.resize(N + 1);
    }
    
    void update(int pos, int val){
        for(int i = pos; i <= N; i += nonZeroLSB(i)){
            tree[i] = max(tree[i], val);
        }
    }
    
    int query(int pos){
        int prefMax = 0;
        for(int i = pos; i >= 1; i -= nonZeroLSB(i)){
            prefMax = max(prefMax, tree[i]);
        }
        return prefMax;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        
        // coordinate compression of vector nums
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        const int U = v.size();
        unordered_map<int, int> originalToCompressed;
        for(int idx = 0; idx < U; ++idx){
            originalToCompressed[v[idx]] = idx;
        }
        
        // At step i:
        //    dp[i]: length of the longest strictly increasing subsequence ending with nums[i]
        //    bitTree.query(R + 1): max dp[k] such that
        //                         (0 <= k <= i - 1) and (0 <= originalToCompressed[nums[k]] <= R)
        // During the algorithm:
        //    For a given pos, we will update our bitTree values only with increasing values VAL1 <= VAL2 <= ... <= VALm
        //    bitTree.update(pos + 1, VAL1): update max value of prefix [0 .. pos] with VAL1
        //    bitTree.update(pos + 1, VAL2): update max value of prefix [0 .. pos] with VAL2
        //    ...
        //    bitTree.update(pos + 1, VALm): update max value of prefix [0 .. pos] with VALm
        vector<int> dp(N);
        BinaryIndexedTree bitTree(U);
        for(int i = 0; i < N; ++i){
            dp[i] = 1 + bitTree.query(originalToCompressed[nums[i]]);
            bitTree.update(originalToCompressed[nums[i]] + 1, dp[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};