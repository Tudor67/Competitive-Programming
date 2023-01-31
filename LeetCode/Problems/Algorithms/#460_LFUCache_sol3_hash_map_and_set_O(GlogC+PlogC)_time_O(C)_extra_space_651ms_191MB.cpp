class LFUCache {
private:
    int capacity;
    int currentTime;
    unordered_map<int, int> valueOf;
    unordered_map<int, int> freqOf;
    unordered_map<int, int> lastTimeOf;
    set<tuple<int, int, int>> cache; // (freqOf[key], lastTimeOf[key], key)

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->currentTime = 0;
    }
    
    int get(int key) {
        if(capacity == 0 || !valueOf.count(key)){
            return -1;
        }
        put(key, valueOf[key]);
        return valueOf[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }

        if(!valueOf.count(key) && (int)valueOf.size() == capacity){
            int keyToRemove = std::get<2>(*cache.begin());
            cache.erase(cache.begin());
            valueOf.erase(keyToRemove);
            freqOf.erase(keyToRemove);
            lastTimeOf.erase(keyToRemove);
        }

        cache.erase({freqOf[key], lastTimeOf[key], key});
        currentTime += 1;
        valueOf[key] = value;
        freqOf[key] += 1;
        lastTimeOf[key] = currentTime;
        cache.insert({freqOf[key], lastTimeOf[key], key});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */