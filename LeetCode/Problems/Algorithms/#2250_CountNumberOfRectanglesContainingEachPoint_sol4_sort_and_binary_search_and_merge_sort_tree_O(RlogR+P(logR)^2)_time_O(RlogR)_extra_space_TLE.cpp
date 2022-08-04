class MergeSortTree{
private:
    const int N;
    vector<vector<int>> tree;
    
    void mergeSort(vector<int>& a, vector<int>& b, vector<int>& c){
        const int N = a.size();
        const int M = b.size();
        c.resize(N + M);
        
        int i = 0;
        int j = 0;
        while(i < N || j < M){
            if(j == M || (i < N && a[i] <= b[j])){
                c[i + j] = a[i];
                i += 1;
            }else{
                c[i + j] = b[j];
                j += 1;
            }
        }
    }
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = {VAL};
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            mergeSort(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
        }
    }
    
    int countGreaterThanOrEqualTo(int node, int l, int r, const int& L, const int& R, const int& THRESHOLD){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            int lowerBoundPos = lower_bound(tree[node].begin(), tree[node].end(), THRESHOLD) - tree[node].begin();
            int count = (int)tree[node].size() - lowerBoundPos;
            return count;
        }
        int mid = (l + r) / 2;
        return countGreaterThanOrEqualTo(2 * node + 1, l, mid, L, R, THRESHOLD) +
               countGreaterThanOrEqualTo(2 * node + 2, mid + 1, r, L, R, THRESHOLD);
    }
    
public:
    MergeSortTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int countGreaterThanOrEqualTo(const int& L, const int& R, const int& THRESHOLD){
        return countGreaterThanOrEqualTo(0, 0, N - 1, L, R, THRESHOLD);
    }
};

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int R = rectangles.size();
        const int P = points.size();
        
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
        
        MergeSortTree tree(R + 1);
        for(int i = 0; i < R; ++i){
            int height = sortedRectangles[i].second;
            tree.update(i, height);
        }
        
        vector<int> res(P);
        for(int j = 0; j < P; ++j){
            int x = points[j][0];
            int y = points[j][1];
            
            if(x > maxRectangleWidth || y > maxRectangleHeight){
                continue;
            }
            
            // binary search min pos i such that sortedRectangles[i .. R - 1].first >= x
            int l = 0;
            int r = R - 1;
            while(l != r){
                int mid = (l + r) / 2;
                if(sortedRectangles[mid].first < x){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            
            int i = r;
            res[j] = tree.countGreaterThanOrEqualTo(i, R - 1, y);
        }
        
        return res;
    }
};