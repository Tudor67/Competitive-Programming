class SegmentTree{
private:
    const int N;
    const function<int(int,int)> OPERATION;
    const int IDENTITY_ELEM;
    vector<int> tree;

    void initTree(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = NUMS[r];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, NUMS);
            initTree(2 * node + 2, mid + 1, r, NUMS);
            tree[node] = OPERATION(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return IDENTITY_ELEM;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return OPERATION(query(2 * node + 1, l, mid, L, R),
                         query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<int>& NUMS, const function<int(int,int)>& OPERATION, const int IDENTITY_ELEM):
                N(NUMS.size()), OPERATION(OPERATION), IDENTITY_ELEM(IDENTITY_ELEM){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, IDENTITY_ELEM);
        initTree(0, 0, N - 1, NUMS);
    }

    int query(const int L, const int R){
        if(L > R){
            return IDENTITY_ELEM;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;
        const int INF = 1e9 + 12345;

        SegmentTree minTree(nums, [](int a, int b) -> int {return min(a, b); },  INF);
        SegmentTree maxTree(nums, [](int a, int b) -> int {return max(a, b); }, -INF);

        // dp[i]: number of valid partitions for nums[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        vector<int> dpSuffSum(N + 2);
        dpSuffSum[N + 1] = 0;
        dpSuffSum[N] = 1;

        int j = N - 1;
        for(int i = N - 1; i >= 0; --i){
            while(maxTree.query(i, j) - minTree.query(i, j) > k){
                j -= 1;
            }
            dp[i] = (dpSuffSum[i + 1] - dpSuffSum[j + 2] + MODULO) % MODULO;
            dpSuffSum[i] = (dp[i] + dpSuffSum[i + 1]) % MODULO;
        }

        return dp[0];
    }
};