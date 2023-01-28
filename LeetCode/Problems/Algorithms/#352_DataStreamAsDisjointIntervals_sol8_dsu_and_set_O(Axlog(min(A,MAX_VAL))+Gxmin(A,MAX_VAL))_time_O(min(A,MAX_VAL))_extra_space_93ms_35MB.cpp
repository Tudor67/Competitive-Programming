class DSU{
private:
    unordered_map<int, int> minVal;
    unordered_map<int, int> maxVal;
    unordered_map<int, int> parent;

public:
    int find(int x){
        if(!parent.count(x)){
            parent[x] = x;
            minVal[x] = x;
            maxVal[x] = x;
        }
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            parent[xRoot] = yRoot;
            minVal[yRoot] = min(minVal[xRoot], minVal[yRoot]);
            maxVal[yRoot] = max(maxVal[xRoot], maxVal[yRoot]);
        }
    }

    int getMinVal(int x){
        return minVal[find(x)];
    }

    int getMaxVal(int x){
        return maxVal[find(x)];
    }
};

class SummaryRanges {
private:
    DSU dsu;
    set<int> dsuRoots;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if(dsuRoots.count(dsu.find(value + 1))){
            dsuRoots.erase(dsu.find(value + 1));
            dsu.join(value, value + 1);
        }

        if(dsuRoots.count(dsu.find(value - 1))){
            dsuRoots.erase(dsu.find(value - 1));
            dsu.join(value - 1, value);
        }

        dsuRoots.insert(dsu.find(value));
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(int root: dsuRoots){
            res.push_back({dsu.getMinVal(root), dsu.getMaxVal(root)});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */