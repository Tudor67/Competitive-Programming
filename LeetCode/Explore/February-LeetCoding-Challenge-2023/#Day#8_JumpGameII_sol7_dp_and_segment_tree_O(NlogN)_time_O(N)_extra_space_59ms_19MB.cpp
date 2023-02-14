class SegmentTree{
private:
    const int N;
    const int INF;
    vector<int> tree;

    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return INF;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int& N, const int& INF): N(N), INF(INF){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, INF);
    }

    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int& L, const int& R){
        if(L > R){
            return INF;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        // minJumps[x]: min jumps to reach position N - 1
        //              when we start from position x
        vector<int> minJumps(N, INF);
        minJumps[N - 1] = 0;

        SegmentTree tree(N, INF);
        tree.update(N - 1, minJumps[N - 1]);
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] >= 1){
                minJumps[i] = 1 + tree.query(i + 1, i + nums[i]);
                tree.update(i, minJumps[i]);
            }
        }

        return minJumps[0];
    }
};