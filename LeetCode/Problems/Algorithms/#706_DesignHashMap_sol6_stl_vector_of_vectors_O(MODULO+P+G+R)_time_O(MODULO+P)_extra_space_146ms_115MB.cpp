class MyHashMap {
private:
    const int MODULO = 66029;
    vector<vector<pair<int, int>>> buckets;

    int getBucketID(int key){
        return key % MODULO;
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
        for(pair<int, int>& P: buckets[bucketID]){
            if(P.first == key){
                return P.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketID = getBucketID(key);
        for(int j = 0; j < (int)buckets[bucketID].size(); ++j){
            if(buckets[bucketID][j].first == key){
                buckets[bucketID][j] = buckets[bucketID].back();
                buckets[bucketID].pop_back();
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