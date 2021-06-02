class SegmentTree{
private:
    const int N;
    const vector<int> A;
    vector<int> tree;
    
    void buildTree(int node, int l, int r){
        if(l == r){
            tree[node] = r;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid);
            buildTree(2 * node + 2, mid + 1, r);
            if(A[tree[2 * node + 1]] <= A[tree[2 * node + 2]]){
                tree[node] = tree[2 * node + 1];
            }else{
                tree[node] = tree[2 * node + 2];
            }
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R) const{
        if(r < L || R < l){
            return -1;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        int leftIdx = query(2 * node + 1, l, mid, L, R);
        int rightIdx = query(2 * node + 2, mid + 1, r, L, R);
        if(leftIdx != -1 && rightIdx != -1){
            if(A[leftIdx] <= A[rightIdx]){
                return leftIdx;
            }else{
                return rightIdx;
            }
        }else if(leftIdx != -1){
            return leftIdx;
        }else if(rightIdx != -1){
            return rightIdx;
        }
        return -1;
    }
    
public:
    SegmentTree(const vector<int>& A): A(A), N(A.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1);
    }
    
    int query(const int& L, const int& R) const{
        if(L > R){
            return -1;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int solve(const vector<int>& A, const int& L, const int& R, int prevOperations, const SegmentTree& SEGMENT_TREE){
        if(L > R){
            return 0;
        }
        int minIdx = SEGMENT_TREE.query(L, R);
        int operations = A[minIdx] - prevOperations;
        return operations + solve(A, L, minIdx - 1, A[minIdx], SEGMENT_TREE) + solve(A, minIdx + 1, R, A[minIdx], SEGMENT_TREE);
    }
    
public:
    int minNumberOperations(vector<int>& target) {
        SegmentTree segmentTree(target);
        return solve(target, 0, (int)target.size() - 1, 0, segmentTree);
    }
};