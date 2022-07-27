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
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        // dpDec[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are decreasing (nums[j] > nums[i])
        // dpInc[i]: length of the longest wiggle subsequence ending with nums[i]
        //           such that the last two elements of subsequence are increasing (nums[j] < nums[i])
        vector<int> dpDec(N);
        vector<int> dpInc(N);
        SegmentTree segmentTreeDec(MAX_NUM + 1);
        SegmentTree segmentTreeInc(MAX_NUM + 1);
        for(int i = 0; i < N; ++i){
            dpDec[i] = segmentTreeInc.query(nums[i] + 1, MAX_NUM) + 1;
            dpInc[i] = segmentTreeDec.query(MIN_NUM, nums[i] - 1) + 1;
            segmentTreeDec.update(nums[i], dpDec[i]);
            segmentTreeInc.update(nums[i], dpInc[i]);
        }
        
        return max(*max_element(dpDec.begin(), dpDec.end()),
                   *max_element(dpInc.begin(), dpInc.end()));
    }
};