class AllOne {
private:
    struct Bucket{
        int freq;
        unordered_set<string> strs;

        Bucket(int freq = 0){
            this->freq = freq;
        }
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketItOf;

public:
    AllOne() {
        buckets.push_back(Bucket(0));
    }
    
    void inc(string key) {
        int freq = (bucketItOf.count(key) ? bucketItOf[key]->freq : 0);

        if(freq == 0){
            buckets.front().strs.insert(key);
            bucketItOf[key] = buckets.begin();
        }

        list<Bucket>::iterator bucketIt = bucketItOf[key];
        if(next(bucketIt) == buckets.end() || freq + 1 != next(bucketIt)->freq){
            buckets.insert(next(bucketIt), Bucket(freq + 1));
        }
        
        bucketIt->strs.erase(key);
        next(bucketIt)->strs.insert(key);
        bucketItOf[key] = next(bucketIt);

        if(bucketIt->freq >= 1 && bucketIt->strs.empty()){
            buckets.erase(bucketIt);
        }
    }
    
    void dec(string key) {
        int freq = (bucketItOf.count(key) ? bucketItOf[key]->freq : 0);

        list<Bucket>::iterator bucketIt = bucketItOf[key];
        if(freq - 1 != prev(bucketIt)->freq){
            buckets.insert(bucketIt, Bucket(freq - 1));
        }
        
        bucketIt->strs.erase(key);
        if(freq - 1 == 0){
            bucketItOf.erase(key);
        }else{
            prev(bucketIt)->strs.insert(key);
            bucketItOf[key] = prev(bucketIt);
        }

        if(bucketIt->strs.empty()){
            buckets.erase(bucketIt);
        }
    }
    
    string getMaxKey() {
        if((int)buckets.size() == 1){
            return "";
        }
        return *buckets.rbegin()->strs.begin();
    }
    
    string getMinKey() {
        if((int)buckets.size() == 1){
            return "";
        }
        return *next(buckets.begin())->strs.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */