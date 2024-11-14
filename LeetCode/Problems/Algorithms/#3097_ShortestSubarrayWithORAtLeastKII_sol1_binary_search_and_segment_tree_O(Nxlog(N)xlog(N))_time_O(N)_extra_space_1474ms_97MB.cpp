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
            tree[node] = tree[2 * node + 1] | tree[2 * node + 2];
        }
    }

    int getOR(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return (getOR(2 * node + 1, l, mid, L, R) |
                getOR(2 * node + 2, mid + 1, r, L, R));
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

    int getOR(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getOR(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        SegmentTree tree(N);
        for(int i = 0; i < N; ++i){
            tree.update(i, nums[i]);
        }

        int minLen = INF;
        for(int i = 0; i < N; ++i){
            int l = i;
            int r = N;
            while(l != r){
                int mid = (l + r) / 2;
                if(tree.getOR(i, mid) < k){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }

            if(r < N){
                minLen = min(minLen, r - i + 1);
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};