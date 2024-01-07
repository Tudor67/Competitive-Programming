class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void update(int node, int l, int r, const int POS, const int VAL){
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

    int getMax(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(getMax(2 * node + 1, l, mid, L, R),
                   getMax(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getMax(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getMax(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        const int U = v.size();
        SegmentTree tree(U);
        // tree.query(L, R): returns max length of a LIS with the last value in range [v[L], v[R]]
        for(int i = 0; i < N; ++i){
            int compressedNum = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            int maxLen = tree.getMax(0, compressedNum - 1) + 1;
            tree.update(compressedNum, maxLen);
        }

        return tree.getMax(0, U - 1);
    }
};