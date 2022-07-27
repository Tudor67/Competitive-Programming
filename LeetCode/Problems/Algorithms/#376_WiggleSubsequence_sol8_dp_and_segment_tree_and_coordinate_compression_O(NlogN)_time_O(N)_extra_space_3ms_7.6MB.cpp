class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        
        // coordinate compression
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        const int U = v.size();
        unordered_map<int, int> originalToCompressed;
        for(int i = 0; i < U; ++i){
            originalToCompressed[v[i]] = i;
        }
        
        // dpDec[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are decreasing (nums[j] > nums[i])
        // dpInc[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are increasing (nums[j] < nums[i])
        vector<int> dpDec(N);
        vector<int> dpInc(N);
        SegmentTree segmentTreeDec(U + 1);
        SegmentTree segmentTreeInc(U + 1);
        for(int i = 0; i < N; ++i){
            int compressedNum = originalToCompressed[nums[i]];
            dpDec[i] = segmentTreeInc.query(compressedNum + 1, U) + 1;
            dpInc[i] = segmentTreeDec.query(0, compressedNum - 1) + 1;
            segmentTreeDec.update(compressedNum, dpDec[i]);
            segmentTreeInc.update(compressedNum, dpInc[i]);
        }
        
        return max(*max_element(dpDec.begin(), dpDec.end()),
                   *max_element(dpInc.begin(), dpInc.end()));
    }
};