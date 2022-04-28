class MyHashMap {
private:
    static const int MODULO = 77977;
    vector<vector<pair<int, int>>> v;
    
    int getHashValue(int key){
        return (key % MODULO);
    }
    
public:
    MyHashMap() {
        v.resize(MODULO);
    }
    
    void put(int key, int value) {
        int hashValue = getHashValue(key);
        for(int j = 0; j < (int)v[hashValue].size(); ++j){
            if(key == v[hashValue][j].first){
                v[hashValue][j].second = value;
                return;
            }
        }
        v[hashValue].emplace_back(key, value);
    }
    
    int get(int key) {
        int hashValue = getHashValue(key);
        for(int j = 0; j < (int)v[hashValue].size(); ++j){
            if(key == v[hashValue][j].first){
                return v[hashValue][j].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = getHashValue(key);
        for(int j = 0; j < (int)v[hashValue].size(); ++j){
            if(key == v[hashValue][j].first){
                v[hashValue][j] = v[hashValue].back();
                v[hashValue].pop_back();
                return;
            }
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