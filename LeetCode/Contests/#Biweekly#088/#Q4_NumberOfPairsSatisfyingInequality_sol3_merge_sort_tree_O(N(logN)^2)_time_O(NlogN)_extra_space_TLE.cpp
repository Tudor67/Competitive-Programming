class MergeSortTree{
private:
    const int N;
    vector<vector<int>> tree;
    
    void mergeSort(vector<int>& A, vector<int>& B, vector<int>& C){
        const int A_SIZE = A.size();
        const int B_SIZE = B.size();
        const int C_SIZE = A_SIZE + B_SIZE;
        
        C.resize(C_SIZE);
        
        int aIndex = 0;
        int bIndex = 0;
        for(int i = 0; i < C_SIZE; ++i){
            if(bIndex == B_SIZE || (aIndex < A_SIZE && A[aIndex] <= B[bIndex])){
                C[i] = A[aIndex];
                aIndex += 1;
            }else{
                C[i] = B[bIndex];
                bIndex += 1;
            }
        }
    }
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = {VAL};
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            mergeSort(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
        }
    }
    
    int countGreaterThanOrEqualTo(int node, int l, int r, const int& L, const int& R, const int& THRESHOLD){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            vector<int>& v = tree[node];
            int count = v.end() - lower_bound(v.begin(), v.end(), THRESHOLD);
            return count;
        }
        int mid = (l + r) / 2;
        return countGreaterThanOrEqualTo(2 * node + 1, l, mid, L, R, THRESHOLD) +
               countGreaterThanOrEqualTo(2 * node + 2, mid + 1, r, L, R, THRESHOLD);
    }
    
public:
    MergeSortTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int countGreaterThanOrEqualTo(const int& L, const int& R, const int& THRESHOLD){
        if(L > R){
            return 0;
        }
        return countGreaterThanOrEqualTo(0, 0, N - 1, L, R, THRESHOLD);
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        const int N = nums1.size();
        
        long long res = 0;
        MergeSortTree tree(N);
        for(int i = N - 1; i >= 0; --i){
            res += tree.countGreaterThanOrEqualTo(i + 1, N - 1, nums1[i] - nums2[i]);
            tree.update(i, nums1[i] - nums2[i] + diff);
        }
        
        return res;
    }
};