class MyHashMap {
private:
    static const int MODULO = 66013;
    vector<vector<pair<int, int>>> h;
    
    pair<int, int> getPos(int key){
        int hashVal = key % MODULO;
        for(int idx = 0; idx < (int)h[hashVal].size(); ++idx){
            if(key == h[hashVal][idx].first){
                return {hashVal, idx};
            }
        }
        return {hashVal, -1};
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        h.resize(MODULO);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto [hashVal, idx] = getPos(key);
        if(idx >= 0){
            h[hashVal][idx].second = value;
        }else{
            h[hashVal].emplace_back(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto [hashVal, idx] = getPos(key);
        if(idx >= 0){
            return h[hashVal][idx].second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto [hashVal, idx] = getPos(key);
        if(idx >= 0){
            h[hashVal][idx] = h[hashVal].back();
            h[hashVal].pop_back();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */