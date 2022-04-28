class MyHashMap {
private:
    static const int MODULO = 77977;
    vector<list<pair<int, int>>> v;
    
    int getHashValue(int key){
        return (key % MODULO);
    }
    
    list<pair<int, int>>::iterator getIterator(int key){
        int hashValue = getHashValue(key);
        for(list<pair<int, int>>::iterator it = v[hashValue].begin(); it != v[hashValue].end(); ++it){
            if(key == it->first){
                return it;
            }
        }
        return v[hashValue].end();
    }
    
public:
    MyHashMap() {
        v.resize(MODULO);
    }
    
    void put(int key, int value) {
        int hashValue = getHashValue(key);
        list<pair<int, int>>::iterator it = getIterator(key);
        if(it == v[hashValue].end()){
            v[hashValue].emplace_back(key, value);
        }else{
            it->second = value;
        }
    }
    
    int get(int key) {
        int hashValue = getHashValue(key);
        list<pair<int, int>>::iterator it = getIterator(key);
        if(it != v[hashValue].end()){
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashValue = getHashValue(key);
        list<pair<int, int>>::iterator it = getIterator(key);
        if(it != v[hashValue].end()){
            v[hashValue].erase(it);
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