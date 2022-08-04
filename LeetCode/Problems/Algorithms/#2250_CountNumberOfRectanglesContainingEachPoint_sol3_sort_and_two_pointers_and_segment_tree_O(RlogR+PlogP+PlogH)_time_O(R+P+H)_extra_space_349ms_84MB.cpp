class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void add(int node, int l, int r, const int& POS, const int& VAL){
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
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void add(const int& POS, const int& VAL){
        add(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int R = rectangles.size();
        const int P = points.size();
        
        // sort rectangles
        vector<pair<int, int>> sortedRectangles(R);
        int maxRectangleWidth = 0;
        int maxRectangleHeight = 0;
        for(int i = 0; i < R; ++i){
            int width = rectangles[i][0];
            int height = rectangles[i][1];
            sortedRectangles[i] = {width, height};
            maxRectangleWidth = max(maxRectangleWidth, width);
            maxRectangleHeight = max(maxRectangleHeight, height);
        }
        
        sort(sortedRectangles.begin(), sortedRectangles.end());
        
        // sort points and keep their indices in the original vector
        vector<tuple<int, int, int>> sortedPointsWithIndices(P);
        for(int j = 0; j < P; ++j){
            sortedPointsWithIndices[j] = {points[j][0], points[j][1], j};
        }
        
        sort(sortedPointsWithIndices.begin(), sortedPointsWithIndices.end());
        
        // solve from right (point with max x) to left (point with min x)
        vector<int> res(P);
        SegmentTree segmentTree(maxRectangleHeight + 1);
        int i = R;
        for(int idx = P - 1; idx >= 0; --idx){
            int x, y, j;
            tie(x, y, j) = sortedPointsWithIndices[idx];
            
            if(x > maxRectangleWidth || y > maxRectangleHeight){
                continue;
            }
            
            while(0 <= i - 1 && x <= sortedRectangles[i - 1].first){
                int height = sortedRectangles[i - 1].second;
                segmentTree.add(height, 1);
                i -= 1;
            }
            
            res[j] = segmentTree.query(y, maxRectangleHeight);
        }
        
        return res;
    }
};