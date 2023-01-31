class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, int> valueOf;
    unordered_map<int, int> freqOf;
    unordered_map<int, list<int>> cache;
    unordered_map<int, list<int>::iterator> cacheIteratorOf;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
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
            int keyToRemove = cache[minFreq].front();
            cache[minFreq].pop_front();
            if(cache[minFreq].empty()){
                cache.erase(minFreq);
            }
            valueOf.erase(keyToRemove);
            freqOf.erase(keyToRemove);
            cacheIteratorOf.erase(keyToRemove);
        }

        if(cacheIteratorOf.count(key)){
            cache[freqOf[key]].erase(cacheIteratorOf[key]);
            cacheIteratorOf.erase(key);
            if(cache[freqOf[key]].empty()){
                cache.erase(freqOf[key]);
            }
            if(minFreq == freqOf[key] && !cache.count(freqOf[key])){
                minFreq += 1;
            }
        }else{
            minFreq = 1;
        }
        
        valueOf[key] = value;
        freqOf[key] += 1;
        cache[freqOf[key]].push_back(key);
        cacheIteratorOf[key] = prev(cache[freqOf[key]].end());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */