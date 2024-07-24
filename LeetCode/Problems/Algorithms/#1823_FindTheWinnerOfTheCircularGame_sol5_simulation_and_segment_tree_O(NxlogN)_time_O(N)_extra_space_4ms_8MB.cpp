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
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int getSum(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return getSum(2 * node + 1, l, mid, L, R) +
               getSum(2 * node + 2, mid + 1, r, L, R);
    }

    int getFirstIndex(int node, int l, int r, int sum){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(sum <= tree[2 * node + 1]){
            return getFirstIndex(2 * node + 1, l, mid, sum);
        }
        return getFirstIndex(2 * node + 2, mid + 1, r, sum - tree[2 * node + 1]);
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

    int getSum(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getSum(0, 0, N - 1, L, R);
    }

    int getFirstIndex(int sum){
        return getFirstIndex(0, 0, N - 1, sum);
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        SegmentTree tree(n);
        for(int i = 0; i < n; ++i){
            tree.update(i, 1);
        }

        int i = 0;
        for(int step = 1; step <= n - 1; ++step){
            int activeFriends = n + 1 - step;
            int targetK = 1 + (k - 1) % activeFriends;
            if(targetK <= tree.getSum(i, n - 1)){
                i = tree.getFirstIndex(tree.getSum(0, i - 1) + targetK);
            }else{
                i = tree.getFirstIndex(targetK - tree.getSum(i, n - 1));
            }
            tree.update(i, 0);
        }
        
        for(int i = 0; i < n; ++i){
            if(tree.getSum(i, i) == 1){
                return i + 1;
            }
        }

        return -1;
    }
};