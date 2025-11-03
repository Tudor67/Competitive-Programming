class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void initTree(int node, int l, int r, const vector<int>& VALUES){
        if(l == r){
            tree[node] = VALUES[r];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, VALUES);
            initTree(2 * node + 2, mid + 1, r, VALUES);
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }

    int queryAND(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return INT_MAX;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return queryAND(2 * node + 1, l, mid, L, R) &
               queryAND(2 * node + 2, mid + 1, r, L, R);
    }

public:
    SegmentTree(const vector<int>& VALUES): N(VALUES.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 1);
        initTree(0, 0, N - 1, VALUES);
    }

    int queryAND(const int L, const int R){
        if(L > R){
            return 0;
        }
        return queryAND(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int lowerBound(const int START_INDEX, int l, int r, SegmentTree& tree, int k){
        while(l != r){
            int mid = (l + r) / 2;
            if(tree.queryAND(START_INDEX, mid) > k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        long long res = 0;
        SegmentTree tree(nums);

        for(int i = 0; i < N; ++i){
            if(nums[i] >= k){
                res += (lowerBound(i, i, N, tree, k - 1) -
                        lowerBound(i, i, N, tree, k));
            }
        }

        return res;
    }
};