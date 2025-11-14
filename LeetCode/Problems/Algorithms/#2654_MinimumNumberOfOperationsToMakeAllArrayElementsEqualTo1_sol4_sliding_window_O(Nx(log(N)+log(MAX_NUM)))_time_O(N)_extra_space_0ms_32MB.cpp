class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void initTree(int node, int l, int r, const vector<int>& NUMS){
        if(l == r){
            tree[node] = NUMS[r];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, NUMS);
            initTree(2 * node + 2, mid + 1, r, NUMS);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getGCD(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return gcd(getGCD(2 * node + 1, l, mid, L, R),
                   getGCD(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<int>& NUMS): N(NUMS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        initTree(0, 0, N - 1, NUMS);
    }

    int getGCD(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getGCD(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int ONES = count(nums.begin(), nums.end(), 1);
        const int INF = 1e9;

        if(ONES >= 1){
            return N - ONES;
        }

        int res = INF;
        SegmentTree tree(nums);
        int l = 0;
        for(int r = 0; r < N; ++r){
            while(l <= r && tree.getGCD(l, r) == 1){
                res = min(res, r - l + N - 1);
                l += 1;
            }
        }

        if(res == INF){
            res = -1;
        }

        return res;
    }
};