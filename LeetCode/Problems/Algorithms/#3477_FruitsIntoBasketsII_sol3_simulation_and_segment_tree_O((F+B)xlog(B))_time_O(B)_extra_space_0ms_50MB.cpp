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

    int getIndexOfFirstGreater(int node, int l, int r, const int VAL){
        if(l == r){
            if(VAL < tree[node]){
                return r;
            }
            return -1;
        }
        int mid = (l + r) / 2;
        if(VAL < tree[2 * node + 1]){
            return getIndexOfFirstGreater(2 * node + 1, l, mid, VAL);
        }
        return getIndexOfFirstGreater(2 * node + 2, mid + 1, r, VAL);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getIndexOfFirstGreater(const int VAL){
        return getIndexOfFirstGreater(0, 0, N - 1, VAL);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int F = fruits.size();
        const int B = baskets.size();

        SegmentTree tree(B);
        for(int basketIndex = 0; basketIndex < B; ++basketIndex){
            tree.update(basketIndex, baskets[basketIndex]);
        }

        int res = 0;
        for(int f: fruits){
            int basketIndex = tree.getIndexOfFirstGreater(f - 1);
            if(0 <= basketIndex && basketIndex < B){
                tree.update(basketIndex, 0);
            }else{
                res += 1;
            }
        }

        return res;
    }
};