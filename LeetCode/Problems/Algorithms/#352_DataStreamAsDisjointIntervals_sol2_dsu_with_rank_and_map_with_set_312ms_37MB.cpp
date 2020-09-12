class DSU{
private:
    map<int, int> parent;
    map<int, int> rank;
    
public:
    int find(int x){
        if(parent.count(x) && parent[x] != x){
            return find(parent[x]);
        }
        return x;
    }
    
    void join(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class SummaryRanges {
private:
    DSU dsu;
    set<int> roots_set;
    map<int, int> min_val;
    map<int, int> max_val;
    set<int> values;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int x) {
        values.insert(x);
        
        int x_root = dsu.find(x);
        int minimum = x;
        int maximum = x;
        vector<int> old_roots = {x_root};
        for(int y: {x - 1, x + 1}){
            if(values.count(y)){
                int y_root = dsu.find(y);
                old_roots.push_back(y_root);
                minimum = min(min_val[y_root], minimum);
                maximum = max(max_val[y_root], maximum);
                dsu.join(x, y);
            }
        }
        
        int x_new_root = dsu.find(x);
        min_val[x_new_root] = minimum;
        max_val[x_new_root] = maximum;
        
        for(int old_root: old_roots){
            roots_set.erase(old_root);
        }
        roots_set.insert(x_new_root);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for(int root: roots_set){
            answer.push_back({min_val[root], max_val[root]});
        }
        return answer;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */