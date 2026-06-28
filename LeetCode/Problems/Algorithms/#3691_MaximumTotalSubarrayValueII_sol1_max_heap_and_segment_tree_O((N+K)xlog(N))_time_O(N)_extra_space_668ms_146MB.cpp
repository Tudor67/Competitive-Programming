template <class OpType>
class SegmentTree {
private:
    const int N;
    const OpType F;
    const int IDENTITY_ELEM;
    vector<int> tree;

    void initTree(int node, int l, int r, const vector<int>& VALUES){
        if(l == r){
            tree[node] = VALUES[r];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, VALUES);
            initTree(2 * node + 2, mid + 1, r, VALUES);
            tree[node] = F(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int get(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return IDENTITY_ELEM;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return F(get(2 * node + 1, l, mid, L, R),
                 get(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<int>& VALUES, const OpType F, const int IDENTITY_ELEM):
               N(VALUES.size()), F(F), IDENTITY_ELEM(IDENTITY_ELEM){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, IDENTITY_ELEM);
        initTree(0, 0, N - 1, VALUES);
    }

    int get(const int L, const int R){
        if(L > R){
            return IDENTITY_ELEM;
        }
        return get(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        const int N = nums.size();

        SegmentTree minTree(nums, [](int a, int b) { return min(a, b); }, INT_MAX);
        SegmentTree maxTree(nums, [](int a, int b) { return max(a, b); }, INT_MIN);

        auto computeDiff = [&](int l, int r) -> int {
            return (maxTree.get(l, r) - minTree.get(l, r));
        };

        long long res = 0;
        priority_queue<array<int, 3>> maxHeap;
        for(int r = 0; r < N; ++r){
            maxHeap.push({computeDiff(0, r), 0, r});
        }
        
        for(int i = 0; i < k; ++i){
            auto [diff, l, r] = maxHeap.top();
            maxHeap.pop();

            res += diff;

            if(l + 1 <= r){
                maxHeap.push({computeDiff(l + 1, r), l + 1, r});
            }
        }

        return res;
    }
};