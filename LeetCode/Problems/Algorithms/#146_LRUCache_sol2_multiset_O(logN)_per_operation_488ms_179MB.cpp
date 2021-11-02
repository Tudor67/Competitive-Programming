class LRUCache {
private:
    int capacity;
    int currentTime;
    unordered_map<int, int> valOf;
    unordered_map<int, int> lastTimeOf;
    multiset<pair<int, int>> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->currentTime = 0;
    }
    
    int get(int key) {
        if(!valOf.count(key)){
            return -1;
        }
        cache.erase(cache.find({lastTimeOf[key], key}));
        currentTime += 1;
        lastTimeOf[key] = currentTime;
        cache.insert({lastTimeOf[key], key});
        return valOf[key];
    }
    
    void put(int key, int value) {
        if(valOf.count(key)){
            cache.erase(cache.find({lastTimeOf[key], key}));
        }else{
            if((int)valOf.size() == capacity){
                int keyToErase = cache.begin()->second;
                valOf.erase(keyToErase);
                lastTimeOf.erase(keyToErase);
                cache.erase(cache.begin());
            }
        }
        currentTime += 1;
        lastTimeOf[key] = currentTime;
        valOf[key] = value;
        cache.insert({lastTimeOf[key], key});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */