class SegmentTree{
private:
    const int N;
    const vector<int> V;
    vector<int> tree;
    
    void initTree(int node, int l, int r){
        if(l == r){
            tree[node] = l;
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid);
            initTree(2 * node + 2, mid + 1, r);
            if(V[tree[2 * node + 1]] <= V[tree[2 * node + 2]]){
                tree[node] = tree[2 * node + 1];
            }else{
                tree[node] = tree[2 * node + 2];
            }
        }
    }
    
    int getIdxOfMin(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return -1;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        int leftIdx = getIdxOfMin(2 * node + 1, l, mid, L, R);
        int rightIdx = getIdxOfMin(2 * node + 2, mid + 1, r, L, R);
        if(leftIdx != -1 && rightIdx != -1){
            if(V[leftIdx] <= V[rightIdx]){
                return leftIdx;
            }else{
                return rightIdx;
            }
        }else if(leftIdx == -1){
            return rightIdx;
        }else{
            return leftIdx;
        }
    }
    
public:
    SegmentTree(const vector<int>& V): N(V.size()), V(V){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        initTree(0, 0, N - 1);
    }
    
    int getIdxOfMin(const int& L, const int& R){
        return getIdxOfMin(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int computeMaxArea(int l, int r, SegmentTree& segmentTree, vector<int>& heights){
        if(l > r){
            return 0;
        }
        if(l == r){
            return heights[l];
        }
        int idxOfMin = segmentTree.getIdxOfMin(l, r);
        int area = heights[idxOfMin] * (r - l + 1);
        int leftMaxArea = computeMaxArea(l, idxOfMin - 1, segmentTree, heights);
        int rightMaxArea = computeMaxArea(idxOfMin + 1, r, segmentTree, heights);
        return max(area, max(leftMaxArea, rightMaxArea));
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        SegmentTree segmentTree(heights);
        return computeMaxArea(0, N - 1, segmentTree, heights);
    }
};