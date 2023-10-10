class MyHashMap {
private:
    const int MODULO = 66029;
    vector<list<pair<int, int>>> buckets;

    int getBucketID(int key){
        return key % MODULO;
    }

    list<pair<int, int>>::iterator getIterator(int key){
        int bucketID = getBucketID(key);
        for(list<pair<int, int>>::iterator it = buckets[bucketID].begin(); it != buckets[bucketID].end(); ++it){
            if(it->first == key){
                return it;
            }
        }
        return buckets[bucketID].end();
    }

public:
    MyHashMap() {
        buckets.assign(MODULO, {});
    }
    
    void put(int key, int value) {
        remove(key);
        buckets[getBucketID(key)].push_back({key, value});
    }
    
    int get(int key) {
        int bucketID = getBucketID(key);
        list<pair<int, int>>::iterator it = getIterator(key);
        if(it != buckets[bucketID].end()){
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketID = getBucketID(key);
        list<pair<int, int>>::iterator it = getIterator(key);
        if(it != buckets[bucketID].end()){
            buckets[bucketID].erase(it);
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