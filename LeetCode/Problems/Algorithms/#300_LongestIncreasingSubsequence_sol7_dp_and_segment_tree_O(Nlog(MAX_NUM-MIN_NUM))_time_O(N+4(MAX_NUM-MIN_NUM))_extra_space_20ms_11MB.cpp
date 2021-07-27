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
        if(R < l || r < L){
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
        tree.resize(2 * minLeaves, 0);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L <= R){
            return query(0, 0, N - 1, L, R);
        }
        return 0;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        // maxLength[i]: length of longest strictly increasing subsequence with last element nums[i]
        vector<int> maxLength(N);
        SegmentTree segmentTree(MAX_NUM - MIN_NUM + 1);
        for(int i = 0; i < N; ++i){
            maxLength[i] = 1 + segmentTree.query(0, nums[i] - MIN_NUM - 1);
            segmentTree.update(nums[i] - MIN_NUM, maxLength[i]);
        }
        
        return *max_element(maxLength.begin(), maxLength.end());
    }
};