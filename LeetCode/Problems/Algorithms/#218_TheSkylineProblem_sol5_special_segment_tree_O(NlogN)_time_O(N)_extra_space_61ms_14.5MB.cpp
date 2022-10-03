class SpecialSegmentTree{
private:
    const int N;
    vector<int> lazy;
    
    void maximizeRange(int node, int l, int r, const int& L, const int& R, const int& POS, const int& VAL){
        if(l == r){
            lazy[node] = max(lazy[node], VAL);
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                maximizeRange(2 * node + 1, l, mid, L, R, POS, VAL);
            }else{
                maximizeRange(2 * node + 2, mid + 1, r, L, R, POS, VAL);
            }
            
            if(L <= l && mid <= R){
                lazy[2 * node + 1] = max(lazy[2 * node + 1], VAL);
            }
            if(L <= mid + 1 && r <= R){
                lazy[2 * node + 2] = max(lazy[2 * node + 2], VAL);
            }
        }
    }
    
    int getMax(int node, int l, int r, const int& POS){
        if(l == r){
            return lazy[node];
        }
        int mid = (l + r) / 2;
        if(POS <= mid){
            return max(lazy[node], getMax(2 * node + 1, l, mid, POS));
        }
        return max(lazy[node], getMax(2 * node + 2, mid + 1, r, POS));
    }
    
public:
    SpecialSegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        lazy.resize(2 * minLeaves);
    }
    
    void maximizeRange(const int& L, const int& R, const int& VAL){
        maximizeRange(0, 0, N - 1, L, R, L, VAL);
        maximizeRange(0, 0, N - 1, L, R, R, VAL);
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

        // special segment tree
        // on compressed ranges [originalToCompressed[x1], originalToCompressed[x2] - 1]
        SpecialSegmentTree tree(U);
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