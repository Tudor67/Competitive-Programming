class LFUCache {
private:
    int capacity;
    int currentTime;
    unordered_map<int, int> cnt;
    unordered_map<int, int> lastTimeOf;
    unordered_map<int, int> valOf;
    multiset<tuple<int, int, int>> cache;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->currentTime = 0;
    }
    
    int get(int key) {
        if(capacity == 0 || !valOf.count(key)){
            return -1;
        }
        cache.erase(cache.find({cnt[key], lastTimeOf[key], key}));
        currentTime += 1;
        cnt[key] += 1;
        lastTimeOf[key] = currentTime;
        cache.insert({cnt[key], lastTimeOf[key], key});
        return valOf[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(valOf.count(key)){
            cache.erase(cache.find({cnt[key], lastTimeOf[key], key}));
        }else{
            if((int)cache.size() == capacity){
                int keyToErase = std::get<2>(*cache.begin());
                cnt.erase(keyToErase);
                lastTimeOf.erase(keyToErase);
                valOf.erase(keyToErase);
                cache.erase(cache.begin());
            }
        }
        currentTime += 1;
        cnt[key] += 1;
        lastTimeOf[key] = currentTime;
        valOf[key] = value;
        cache.insert({cnt[key], lastTimeOf[key], key});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */