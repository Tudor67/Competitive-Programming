class SegmentTree{
private:
    const int N;
    const int IDENTITY_ELEM;
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

    int query(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return IDENTITY_ELEM;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N, const int IDENTITY_ELEM): N(N), IDENTITY_ELEM(IDENTITY_ELEM){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, IDENTITY_ELEM);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int L, const int R){
        if(L > R){
            return IDENTITY_ELEM;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int getCompressedValue(long long x, vector<int>& sortedValues){
        return lower_bound(sortedValues.begin(), sortedValues.end(), x) - sortedValues.begin();
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        SegmentTree tree(v.size(), -1);
        tree.update(getCompressedValue(nums[0], v), 0);

        for(int i = 1; i < N; ++i){
            int l = getCompressedValue(nums[i] - (long long)target, v);
            int r = getCompressedValue(nums[i] + (long long)target + 1, v) - 1;
            int prevMaxJumps = tree.query(l, r);
            if(prevMaxJumps >= 0){
                int maxJumps = prevMaxJumps + 1;
                int compressedNum = getCompressedValue(nums[i], v);
                tree.update(compressedNum, maxJumps);
            }
        }

        int compressedNum = getCompressedValue(nums[N - 1], v);
        return tree.query(compressedNum, compressedNum);
    }
};