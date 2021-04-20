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
        if(L > R){
            return 0;
        }
        return query(R) - query(L - 1);
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        const int N = nums.size();
        
        // Step 1: save nums[i] and 2 * nums[i] in nums2
        //         sort nums2
        vector<long long> nums2(2 * N);
        for(int i = 0; i < N; ++i){
            nums2[i] = nums[i];
            nums2[i + N] = 2LL * nums[i];
        }
        
        sort(nums2.begin(), nums2.end());
        
        // Step 2: value compression
        map<long long, int> compressedValueOf;
        int idx = 0;
        for(long long num: nums2){
            idx += 1;
            compressedValueOf[num] = idx;
        }
        
        // Step 3: use a binary indexed tree to count important reverse pairs
        const int M = idx;
        int answer = 0;
        BinaryIndexedTree bitTree(M);
        for(int i = N - 1; i >= 0; --i){
            answer += bitTree.query(1, compressedValueOf[nums[i]] - 1);
            bitTree.add(compressedValueOf[2LL * nums[i]], 1);
        }
        
        return answer;
    }
};