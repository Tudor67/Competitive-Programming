class SegmentTree{
private:
    const int N;
    const int MODULO;
    vector<int> tree;

    int getSum(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return (getSum(2 * node + 1, l, mid, L, R) +
                getSum(2 * node + 2, mid + 1, r, L, R)) % MODULO;
    }

    void add(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = (tree[node] + VAL) % MODULO;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MODULO;
        }
    }

public:
    SegmentTree(const int N, const int MODULO): N(N), MODULO(MODULO){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    int getVal(const int POS){
        return getSum(0, 0, N - 1, 0, POS);
    }

    void add(const int L, const int R, const int VAL){
        if(L <= R){
            add(0, 0, N - 1, L, VAL);
            add(0, 0, N - 1, R + 1, (MODULO - VAL) % MODULO);
        }
    }
};

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MODULO = 1'000'000'007;

        SegmentTree knowTree(n + 2, MODULO);
        SegmentTree shareTree(n + 2, MODULO);
        shareTree.add(1, 1, 1);

        for(int i = 1; i <= n; ++i){
            int shareVal = shareTree.getVal(i);
            knowTree.add(i, min(i + forget - 1, n), shareVal);
            shareTree.add(min(i + delay, n + 1), min(i + forget - 1, n + 1), shareVal);
        }

        return knowTree.getVal(n);
    }
};