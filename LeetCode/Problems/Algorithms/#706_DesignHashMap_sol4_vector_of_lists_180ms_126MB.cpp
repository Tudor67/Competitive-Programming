class MyHashMap {
private:
    static const int MODULO = 77977;
    vector<list<pair<int, int>>> v;
    
    int getHashValue(int key){
        return (key % MODULO);
    }
    
public:
    MyHashMap() {
        v.resize(MODULO);
    }
    
    void put(int key, int value) {
        int hashValue = getHashValue(key);
        for(list<pair<int, int>>::iterator it = v[hashValue].begin(); it != v[hashValue].end(); ++it){
            if(key == it->first){
                it->second = value;
                return;
            }
        }
        v[hashValue].emplace_back(key, value);
    }
    
    int get(int key) {
        int hashValue = getHashValue(key);
        for(list<pair<int, int>>::iterator it = v[hashValue].begin(); it != v[hashValue].end(); ++it){
            if(key == it->first){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = getHashValue(key);
        for(list<pair<int, int>>::iterator it = v[hashValue].begin(); it != v[hashValue].end(); ++it){
            if(key == it->first){
                v[hashValue].erase(it);
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