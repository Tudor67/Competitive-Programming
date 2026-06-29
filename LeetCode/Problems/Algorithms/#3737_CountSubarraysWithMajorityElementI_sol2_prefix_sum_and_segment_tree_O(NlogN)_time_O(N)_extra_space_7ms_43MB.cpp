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
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int N = nums.size();
        const int MIN_DIFF = -(N - 1);
        const int MAX_DIFF = N + 1;
        const int SHIFT = N - 1;

        int majoritySubarrays = 0;
        int prefCountOfTarget = 0;
        SegmentTree tree(MAX_DIFF + SHIFT + 1);
        tree.add(2 * prefCountOfTarget - (-1) + SHIFT, 1);
        
        for(int i = 0; i < N; ++i){
            if(nums[i] == target){
                prefCountOfTarget += 1;
            }

            int currDiff = 2 * prefCountOfTarget - i;
            majoritySubarrays += tree.getSum(0, currDiff - 1 + SHIFT);

            tree.add(currDiff + SHIFT, 1);
        }

        return majoritySubarrays;
    }
};