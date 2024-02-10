class SegmentTree{
private:
    const int N;
    const int IDENTITY_ELEMENT;
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
            return IDENTITY_ELEMENT;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(getMax(2 * node + 1, l, mid, L, R),
                   getMax(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N, const int IDENTITY_ELEMENT): N(N), IDENTITY_ELEMENT(IDENTITY_ELEMENT){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, IDENTITY_ELEMENT);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getMax(const int L, const int R){
        if(L > R){
            return IDENTITY_ELEMENT;
        }
        return getMax(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        const int N = nums.size();
        const int INF = 1e9;

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        int res = INF;
        SegmentTree tree(N, -INF);
        for(const pair<int, int>& P: v){
            int i = P.second;
            tree.update(i, nums[i]);
            res = min(res, nums[i] - tree.getMax(0, i - x));
            res = min(res, nums[i] - tree.getMax(i + x, N - 1));
        }

        return res;
    }
};