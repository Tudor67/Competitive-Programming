class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void flipRange(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            tree[node] ^= 1;
        }else{
            int mid = (l + r) / 2;
            flipRange(2 * node + 1, l, mid, L, R);
            flipRange(2 * node + 2, mid + 1, r, L, R);
        }
    }

    int getVal(int node, int l, int r, const int POS){
        if(l == r){
            return tree[node];
        }
        int mid = (l + r) / 2;
        if(POS <= mid){
            return (tree[node] ^ getVal(2 * node + 1, l, mid, POS));
        }
        return (tree[node] ^ getVal(2 * node + 2, mid + 1, r, POS));
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }

    void flipRange(const int L, const int R){
        if(L <= R){
            flipRange(0, 0, N - 1, L, R);
        }
    }

    int getVal(const int POS){
        return getVal(0, 0, N - 1, POS);
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int N = nums.size();

        int minFlips = 0;
        SegmentTree tree(N);

        for(int i = 0; i < N; ++i){
            if((nums[i] ^ tree.getVal(i)) == 0){
                if(i + k - 1 < N){
                    minFlips += 1;
                    tree.flipRange(i, i + k - 1);
                }else{
                    minFlips = -1;
                    break;
                }
            }
        }

        return minFlips;
    }
};