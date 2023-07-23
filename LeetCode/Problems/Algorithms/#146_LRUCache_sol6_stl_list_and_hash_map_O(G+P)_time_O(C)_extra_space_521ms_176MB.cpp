class LRUCache {
private:
    int capacity;
    list<int> cache;
    unordered_map<int, int> valOf;
    unordered_map<int, list<int>::iterator> itOf;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!itOf.count(key)){
            return -1;
        }
        cache.erase(itOf[key]);
        itOf[key] = cache.insert(cache.end(), key);
        return valOf[key];
    }
    
    void put(int key, int value) {
        if((int)cache.size() == capacity && !itOf.count(key)){
            int oldKey = cache.front();
            cache.erase(cache.begin());
            itOf.erase(oldKey);
            valOf.erase(oldKey);
        }
        if(itOf.count(key)){
            cache.erase(itOf[key]);
        }
        itOf[key] = cache.insert(cache.end(), key);
        valOf[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */