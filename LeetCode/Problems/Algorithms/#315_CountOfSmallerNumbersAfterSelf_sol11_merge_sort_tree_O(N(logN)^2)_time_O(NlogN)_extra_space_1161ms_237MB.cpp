class MergeSortTree{
private:
    const int N;
    vector<vector<int>> tree;
    
    void mergeSort(vector<int>& a, vector<int>& b, vector<int>& c){
        const int A_SIZE = a.size();
        const int B_SIZE = b.size();
        
        c.reserve(A_SIZE + B_SIZE);
        
        int aIdx = 0;
        int bIdx = 0;
        while(aIdx < A_SIZE && bIdx < B_SIZE){
            if(a[aIdx] <= b[bIdx]){
                c.push_back(a[aIdx]);
                aIdx += 1;
            }else{
                c.push_back(b[bIdx]);
                bIdx += 1;
            }
        }
        
        copy(a.begin() + aIdx, a.end(), back_inserter(c));
        copy(b.begin() + bIdx, b.end(), back_inserter(c));
    }
    
    void buildTree(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = {NUMS[r]};
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, NUMS);
            buildTree(2 * node + 2, mid + 1, r, NUMS);
            mergeSort(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
        }
    }
    
    int countLess(int node, int l, int r, const int& L, const int& R, const int& THR){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return lower_bound(tree[node].begin(), tree[node].end(), THR) - tree[node].begin();
        }
        int mid = (l + r) / 2;
        return countLess(2 * node + 1, l, mid, L, R, THR) +
               countLess(2 * node + 2, mid + 1, r, L, R, THR);
    }
    
public:
    MergeSortTree(const vector<int>& NUMS): N(NUMS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, NUMS);
    }
    
    int countLess(const int& L, const int& R, const int& THR){
        if(L > R){
            return 0;
        }
        return countLess(0, 0, N - 1, L, R, THR);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        
        MergeSortTree tree(nums);
        vector<int> count(N);
        for(int i = 0; i < N; ++i){
            count[i] = tree.countLess(i + 1, N, nums[i]);
        }
        
        return count;
    }
};