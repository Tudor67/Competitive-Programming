class BinaryIndexedTree{
private:
    const int N;
    vector<int> a;
    
public:
    BinaryIndexedTree(const int& N): N(N){
        a.resize(N + 1);
    }
    
    void add(const int& POS, const int& VAL){
        for(int i = POS; i <= N; i += i - (i & (i - 1))){
            a[i] += VAL;
        }
    }
    
    int query(const int& R){
        int sum = 0;
        for(int i = R; i >= 1; i &= (i - 1)){
            sum += a[i];
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        
        // Step 1: value compression
        vector<int> v = nums;
        sort(v.begin(), v.end());
        
        map<int, int> compressedValue;
        int idx = 1;
        compressedValue[v[0]] = 1;
        for(int i = 1; i < N; ++i){
            if(v[i] != v[i - 1]){
                idx += 1;
                compressedValue[v[i]] = idx;
            }
        }
        
        // Step 2: use binary indexed tree to mark visited elements and to count elements less than current num
        vector<int> counts(N);
        BinaryIndexedTree tree(N);
        for(int i = N - 1; i >= 0; --i){
            counts[i] = tree.query(compressedValue[nums[i]] - 1);
            tree.add(compressedValue[nums[i]], 1);
        }
        
        return counts;
    }
};