class LRUCache {
private:
    int capacity;
    unordered_map<int, int> valOf;
    unordered_map<int, list<int>::iterator> itInCache;
    list<int> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!valOf.count(key)){
            return -1;
        }
        cache.erase(itInCache[key]);
        cache.push_front(key);
        itInCache[key] = cache.begin();
        return valOf[key];
    }
    
    void put(int key, int value) {
        if(valOf.count(key)){
            cache.erase(itInCache[key]);
        }else{
            if((int)valOf.size() == capacity){
                int keyToErase = cache.back();
                valOf.erase(keyToErase);
                cache.erase(itInCache[keyToErase]);
                itInCache.erase(keyToErase);
            }
        }
        cache.push_front(key);
        itInCache[key] = cache.begin();
        valOf[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */