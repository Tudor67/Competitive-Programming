class SegmentTree{
private:
    const int N;
    vector<int> tree;
    vector<int> lazy;

    void propagate(int node, int l, int r){
        tree[node] += lazy[node] * (r - l + 1);
        if(l != r){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void add(int node, int l, int r, const int L, const int R, const int VAL){
        propagate(node, l, r);
        if(R < l || r < L){
            return;
        }
        if(L <= l && r <= R){
            lazy[node] += VAL;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        add(2 * node + 1, l, mid, L, R, VAL);
        add(2 * node + 2, mid + 1, r, L, R, VAL);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int querySum(int node, int l, int r, const int L, const int R){
        propagate(node, l, r);
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return querySum(2 * node + 1, l, mid, L, R) +
               querySum(2 * node + 2, mid + 1, r, L, R);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
        lazy.assign(2 * minLeaves, 0);
    }

    void add(const int L, const int R, const int VAL){
        add(0, 0, N - 1, L, R, VAL);
    }

    int querySum(const int L, const int R){
        return querySum(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        int iContrib = 0;
        map<int, int> prevIndexOf;
        SegmentTree tree(N);

        for(int i = 0; i < N; ++i){
            int j = (prevIndexOf.contains(nums[i]) ? prevIndexOf[nums[i]] : -1);
            iContrib += (2 * tree.querySum(j + 1, i) + i - j);
            res += iContrib;
            prevIndexOf[nums[i]] = i;
            tree.add(j + 1, i, 1);
        }

        return res;
    }
};