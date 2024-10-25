class BinaryIndexedTree{
private:
    const int N;
    vector<int> tree;

    static int nonZeroLSB(int x){
        return x - (x & (x - 1));
    }

public:
    BinaryIndexedTree(const int N): N(N){
        tree.resize(N);
    }

    void add(int pos, int val){
        for(int i = pos; i < N; i += nonZeroLSB(i)){
            tree[i] += val;
        }
    }

    int computePrefixSum(int pos){
        int sum = 0;
        for(int i = pos; i >= 1; i -= nonZeroLSB(i)){
            sum += tree[i];
        }
        return sum;
    }

    int computeSuffixSum(int pos){
        return computePrefixSum(N - 1) - computePrefixSum(pos - 1);
    }
};

class Solution {
private:
    int compress(vector<int>& sortedNums, int num){
        return lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin() + 1;
    }
    
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());
        
        vector<int> arr0 = {nums[0]};
        vector<int> arr1 = {nums[1]};
        
        BinaryIndexedTree tree0(sortedNums.size() + 1);
        BinaryIndexedTree tree1(sortedNums.size() + 1);
        tree0.add(compress(sortedNums, arr0[0]), 1);
        tree1.add(compress(sortedNums, arr1[0]), 1);
        
        for(int i = 2; i < N; ++i){
            int compressedNum = compress(sortedNums, nums[i]);
            int g0 = tree0.computeSuffixSum(compressedNum + 1);
            int g1 = tree1.computeSuffixSum(compressedNum + 1);
            if((g0 > g1) || (g0 == g1 && arr0.size() <= arr1.size())){
                arr0.push_back(nums[i]);
                tree0.add(compressedNum, 1);
            }else{
                arr1.push_back(nums[i]);
                tree1.add(compressedNum, 1);
            }
        }
        
        vector<int> res;
        copy(arr0.begin(), arr0.end(), back_inserter(res));
        copy(arr1.begin(), arr1.end(), back_inserter(res));
        
        return res;
    }
};