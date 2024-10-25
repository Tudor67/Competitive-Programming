class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void add(int node, int l, int r, int pos, int val){
        if(l == r){
            tree[node] += val;
        }else{
            int mid = (l + r) / 2;
            if(pos <= mid){
                add(2 * node + 1, l, mid, pos, val);
            }else{
                add(2 * node + 2, mid + 1, r, pos, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int computeSum(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return computeSum(2 * node + 1, l, mid, L, R) +
               computeSum(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void add(int pos, int val){
        add(0, 0, N - 1, pos, val);
    }
    
    int computeSuffixSum(const int L){
        if(L >= N){
            return 0;
        }
        return computeSum(0, 0, N - 1, L, N - 1);
    }
};

class Solution {
private:
    int compress(vector<int>& sortedNums, int num){
        return lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin();
    }
    
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());
        
        vector<int> arr0 = {nums[0]};
        vector<int> arr1 = {nums[1]};
        
        SegmentTree tree0(sortedNums.size());
        SegmentTree tree1(sortedNums.size());
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