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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();

        vector<int> pos2(N);
        for(int i = 0; i < N; ++i){
            pos2[nums2[i]] = i;
        }

        vector<int> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = pos2[nums1[i]];
        }

        long long goodTriplets = 0;
        SegmentTree leftTree(N);
        for(int i = 0; i < N; ++i){
            long long leftCount = leftTree.getSum(0, v[i] - 1);
            long long rightCount = N - (i + 1) - (v[i] - leftCount);
            goodTriplets += (leftCount * rightCount);
            leftTree.add(v[i], 1);
        }

        return goodTriplets;
    }
};