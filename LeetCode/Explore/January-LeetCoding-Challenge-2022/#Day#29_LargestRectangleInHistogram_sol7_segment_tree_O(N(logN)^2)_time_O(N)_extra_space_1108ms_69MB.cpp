class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void initTree(int node, int l, int r, const vector<int>& V){
        if(l == r){
            tree[node] = V[l];
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, V);
            initTree(2 * node + 2, mid + 1, r, V);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return INT_MAX;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
    int prevSmaller(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            return l;
        }
        int mid = (l + r) / 2;
        if(mid + 1 <= POS - 1 && query(0, 0, N - 1, mid + 1, POS - 1) < VAL){
            return prevSmaller(2 * node + 2, mid + 1, r, POS, VAL);
        }
        return prevSmaller(2 * node + 1, l, mid, POS, VAL);
    }
    
    int nextSmaller(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            return l;
        }
        int mid = (l + r) / 2;
        if(POS + 1 <= mid && query(0, 0, N - 1, POS + 1, mid) < VAL){
            return nextSmaller(2 * node + 1, l, mid, POS, VAL);
        }
        return nextSmaller(2 * node + 2, mid + 1, r, POS, VAL);
    }
    
public:
    SegmentTree(const vector<int>& V): N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        initTree(0, 0, N - 1, V);
    }
    
    int prevSmaller(const int& POS, const int& VAL){
        if(POS == 0 || query(0, 0, N - 1, 0, POS - 1) >= VAL){
            return -1;
        }
        return prevSmaller(0, 0, N - 1, POS, VAL);
    }
    
    int nextSmaller(const int& POS, const int& VAL){
        if(POS == N - 1 || query(0, 0, N - 1, POS + 1, N - 1) >= VAL){
            return N;
        }
        return nextSmaller(0, 0, N - 1, POS, VAL);
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        
        int maxArea = 0;
        SegmentTree segmentTree(heights);
        for(int i = 0; i < N; ++i){
            int prevSmaller = segmentTree.prevSmaller(i, heights[i]);
            int nextSmaller = segmentTree.nextSmaller(i, heights[i]);
            int area = heights[i] * (nextSmaller - prevSmaller - 1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};