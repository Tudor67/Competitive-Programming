class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void add(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
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

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    void reset(){
        fill(tree.begin(), tree.end(), 0);
    }

    void add(const int POS, const int VAL){
        add(0, 0, N - 1, POS, VAL);
    }

    int getSum(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getSum(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int N = arr.size();

        vector<int> v(5 * N);
        for(int i = 0; i < N; ++i){
            v[i] = arr[i];
            v[i + N] = arr[i] - c;
            v[i + 2 * N] = arr[i] + c;
            v[i + 3 * N] = arr[i] - b;
            v[i + 4 * N] = arr[i] + b;
        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        auto compress = [&](int elem) -> int {
            return lower_bound(v.begin(), v.end(), elem) - v.begin();
        };

        const int MAX_COMPRESSED = compress(v.back());
        SegmentTree tree(MAX_COMPRESSED + 1);

        int goodTriplets = 0;
        for(int i = 0; i < N; ++i){
            tree.reset();
            for(int j = N - 1; j >= i + 1; --j){
                if(abs(arr[i] - arr[j]) <= a){
                    int l = compress(max(arr[i] - c, arr[j] - b));
                    int r = compress(min(arr[i] + c, arr[j] + b));
                    goodTriplets += tree.getSum(l, r);
                }
                tree.add(compress(arr[j]), 1);
            }
        }

        return goodTriplets;
    }
};