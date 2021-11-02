class LFUCache {
private:
    int capacity;
    int minCnt;
    unordered_map<int, int> cnt;
    unordered_map<int, list<int>::iterator> itInCache;
    unordered_map<int, int> valOf;
    unordered_map<int, list<int>> cache;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minCnt = 1;
    }
    
    int get(int key) {
        if(capacity == 0 || !valOf.count(key)){
            return -1;
        }
        cache[cnt[key]].erase(itInCache[key]);
        if(cache[cnt[key]].empty()){
            cache.erase(cnt[key]);
            if(minCnt == cnt[key]){
                minCnt += 1;
            }
        }
        cnt[key] += 1;
        cache[cnt[key]].push_front(key);
        itInCache[key] = cache[cnt[key]].begin();
        return valOf[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(valOf.count(key)){
            cache[cnt[key]].erase(itInCache[key]);
            if(cache[cnt[key]].empty()){
                cache.erase(cnt[key]);
                if(minCnt == cnt[key]){
                    minCnt += 1;
                }
            }
        }else{
            if((int)valOf.size() == capacity){
                int keyToErase = cache[minCnt].back();
                cnt.erase(keyToErase);
                valOf.erase(keyToErase);
                cache[cnt[keyToErase]].erase(itInCache[keyToErase]);
                itInCache.erase(keyToErase);
                if(cache[cnt[keyToErase]].empty()){
                    cache.erase(cnt[keyToErase]);
                }
            }
            minCnt = 1;
        }
        cnt[key] += 1;
        cache[cnt[key]].push_front(key);
        itInCache[key] = cache[cnt[key]].begin();
        valOf[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */