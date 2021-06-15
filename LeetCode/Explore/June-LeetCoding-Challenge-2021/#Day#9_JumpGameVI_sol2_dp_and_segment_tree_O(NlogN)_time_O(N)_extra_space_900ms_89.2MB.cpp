class SegmentTree{
private:
    const int N;
    const int IDENTITY_ELEMENT;
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
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return IDENTITY_ELEMENT;
        }else if(L <= l && r <= R){
            return tree[node];
        }else{
            int mid = (l + r) / 2;
            return max(query(2 * node + 1, l, mid, L, R),
                       query(2 * node + 2, mid + 1, r, L, R));
        }
    }
    
public:
    SegmentTree(const int& N, const int& IDENTITY_ELEMENT): N(N), IDENTITY_ELEMENT(IDENTITY_ELEMENT){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, IDENTITY_ELEMENT);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        vector<int> maxScore(N);
        maxScore[0] = nums[0];
        SegmentTree segmentTree(N, -INF);
        segmentTree.update(0, maxScore[0]);
        for(int i = 1; i < N; ++i){
            maxScore[i] = nums[i] + segmentTree.query(max(0, i - k), i - 1);
            segmentTree.update(i, maxScore[i]);
        }
        return maxScore[N - 1];
    }
};