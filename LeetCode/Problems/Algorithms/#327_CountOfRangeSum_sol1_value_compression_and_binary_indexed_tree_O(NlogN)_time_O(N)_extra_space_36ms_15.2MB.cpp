class BinaryIndexedTree{
private:
    const int N;
    vector<int> a;
    
    static int nonZeroLSB(int num){
        return num - (num & (num - 1));
    }
    
    int query(const int& R){
        int sum = 0;
        for(int i = R; i >= 1; i -= nonZeroLSB(i)){
            sum += a[i];
        }
        return sum;
    }
    
public:
    BinaryIndexedTree(const int& N): N(N){
        a.resize(N + 1);
    }
    
    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += nonZeroLSB(i)){
            a[i] += VAL;
        }
    }
    
    int query(const int& L, const int& R){
        return query(R) - query(L - 1);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();
        
        // Step 1: prefix sum
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        // Step 2: value compression (for prefSum, prefSum - upper, prefSum - lower)
        vector<long long> v(3 * N + 1);
        for(int i = 0; i < N; ++i){
            v[i] = prefSum[i];
            v[i + N] = prefSum[i] - upper;
            v[i + 2 * N] = prefSum[i] - lower;
        }
        v[3 * N] = 0;
        sort(v.begin(), v.end());
        
        map<long long, int> compressedValueOf;
        int idx = 1;
        compressedValueOf[v[0]] = 1;
        for(int i = 1; i < 3 * N + 1; ++i){
            if(v[i] != v[i - 1]){
                idx += 1;
                compressedValueOf[v[i]] = idx;
            }
        }
        
        // Step 3: use binary indexed tree to count prefSums in range [prefSum - upper, prefSum - lower]  
        int answer = 0;
        BinaryIndexedTree tree((int)compressedValueOf.size());
        tree.add(compressedValueOf[0], 1);
        for(int i = 0; i < N; ++i){
            int val = compressedValueOf[prefSum[i]];
            int l = compressedValueOf[prefSum[i] - upper];
            int r = compressedValueOf[prefSum[i] - lower];
            answer += tree.query(l, r);
            tree.add(val, 1);
        }
        
        return answer;
    }
};