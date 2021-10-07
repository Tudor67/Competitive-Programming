class SegmentTree{
private:
    const int N;
    vector<bool> tree;
    
    void update(int node, int l, int r, const int& POS, const bool& VAL){
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
    
    bool query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return false;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) |
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, false);
    }
    
    void update(const int& POS, const bool& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    bool query(const int& L, const int& R){
        if(L > R){
            return false;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {    
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        vector<bool> isPossible(N, false);
        isPossible[0] = (s[0] == '0');
        SegmentTree segmentTree(N);
        segmentTree.update(0, isPossible[0]);
        for(int i = 1; i <= N - 1; ++i){
            if(s[i] == '0'){
                isPossible[i] = segmentTree.query(max(0, i - maxJump), i - minJump);
                segmentTree.update(i, isPossible[i]);
            }
        }
        return isPossible[N - 1];
    }
};