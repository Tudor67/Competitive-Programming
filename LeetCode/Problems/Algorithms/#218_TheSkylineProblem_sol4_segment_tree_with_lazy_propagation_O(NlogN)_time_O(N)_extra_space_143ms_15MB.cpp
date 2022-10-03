class SegmentTree{
private:
    const int N;
    vector<int> tree;
    vector<int> lazy;
    
    void propagate(int node){
        tree[node] = max(tree[node], lazy[node]);
        if(2 * node + 2 < (int)lazy.size()){
            lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
            lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);
        }
        lazy[node] = 0;
    }
    
    void maximizeRange(int node, int l, int r, const int& L, const int& R, const int& VAL){
        propagate(node);
        if(R < l || r < L){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] = VAL;
            propagate(node);
        }else{
            int mid = (l + r) / 2;
            maximizeRange(2 * node + 1, l, mid, L, R, VAL);
            maximizeRange(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int getMax(int node, int l, int r, const int& POS){
        propagate(node);
        if(l == r){
            return tree[node];
        }
        int mid = (l + r) / 2;
        if(POS <= mid){
            return getMax(2 * node + 1, l, mid, POS);
        }
        return getMax(2 * node + 2, mid + 1, r, POS);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        lazy.resize(2 * minLeaves);
    }
    
    void maximizeRange(const int& L, const int& R, const int& VAL){
        maximizeRange(0, 0, N - 1, L, R, VAL);
    }
    
    int getMax(const int& POS){
        return getMax(0, 0, N - 1, POS);
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        const int N = buildings.size();
        
        // coordinate compression for x
        vector<int> xCoordinates;
        for(int i = 0; i < N; ++i){
            int x1 = buildings[i][0];
            int x2 = buildings[i][1];
            xCoordinates.push_back(x1);
            xCoordinates.push_back(x2);
        }
        
        sort(xCoordinates.begin(), xCoordinates.end());
        xCoordinates.resize(unique(xCoordinates.begin(), xCoordinates.end()) - xCoordinates.begin());
        
        const int U = xCoordinates.size();
        unordered_map<int, int> originalToCompressed;
        for(int i = 0; i < U; ++i){
            originalToCompressed[xCoordinates[i]] = i;
        }
        
        // segment tree (with lazy propagation)
        // on compressed ranges [originalToCompressed[x1], originalToCompressed[x2] - 1]
        SegmentTree tree(U);
        for(int i = 0; i < N; ++i){
            int x1 = buildings[i][0];
            int x2 = buildings[i][1];
            int height = buildings[i][2];
            tree.maximizeRange(originalToCompressed[x1], originalToCompressed[x2] - 1, height);
        }
        
        // collect valid key points
        vector<vector<int>> keyPoints;
        for(int x: xCoordinates){
            int maxHeight = tree.getMax(originalToCompressed[x]);
            if(keyPoints.empty() || keyPoints.back()[1] != maxHeight){
                keyPoints.push_back({x, maxHeight});
            }
        }
        
        return keyPoints;
    }
};