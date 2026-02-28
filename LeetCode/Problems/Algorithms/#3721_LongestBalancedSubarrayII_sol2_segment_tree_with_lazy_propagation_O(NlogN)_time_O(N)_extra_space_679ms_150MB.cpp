class SegmentTree{
private:
    const int N;
    vector<int> lazy;
    vector<int> mn;
    vector<int> mx;

    void propagate(int node, int l, int r){
        mn[node] += lazy[node];
        mx[node] += lazy[node];
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
        mn[node] = min(mn[2 * node + 1], mn[2 * node + 2]);
        mx[node] = max(mx[2 * node + 1], mx[2 * node + 2]);
    }

    int getRightmostIndexOfZero(int node, int l, int r){
        propagate(node, l, r);
        if(0 < mn[node] || mx[node] < 0){
            return -1;
        }
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(mn[2 * node + 2] + lazy[2 * node + 2] <= 0 && 0 <= mx[2 * node + 2] + lazy[2 * node + 2]){
            return getRightmostIndexOfZero(2 * node + 2, mid + 1, r);
        }
        return getRightmostIndexOfZero(2 * node + 1, l, mid);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        lazy.assign(2 * minLeaves, 0);
        mn.assign(2 * minLeaves, 0);
        mx.assign(2 * minLeaves, 0);
    }

    void add(const int L, const int R, const int VAL){
        add(0, 0, N - 1, L, R, VAL);
    }

    int getRightmostIndexOfZero(){
        return getRightmostIndexOfZero(0, 0, N - 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        unordered_map<int, int> nextIndexOf;
        SegmentTree tree(N);

        for(int i = N - 1; i >= 0; --i){
            int delta = (nums[i] % 2 == 0 ? -1 : 1);
            int j = (nextIndexOf.count(nums[i]) ? nextIndexOf[nums[i]] : N);
            tree.add(i, j - 1, delta);
            maxLen = max(maxLen, tree.getRightmostIndexOfZero() - i + 1);
            nextIndexOf[nums[i]] = i;
        }

        return maxLen;
    }
};