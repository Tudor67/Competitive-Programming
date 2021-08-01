class MapSum {
private:
    unordered_map<string, int> sumOfPrefix;
    unordered_map<string, int> valOf;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int diff = val;
        if(valOf.count(key)){
            diff -= valOf[key];
        }
        for(int i = 0; i < (int)key.length(); ++i){
            string prefix = key.substr(0, i + 1);
            sumOfPrefix[prefix] += diff;
        }
        valOf[key] = val;
    }
    
    int sum(string prefix) {
        if(sumOfPrefix.count(prefix)){
            return sumOfPrefix[prefix];
        }
        return 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */