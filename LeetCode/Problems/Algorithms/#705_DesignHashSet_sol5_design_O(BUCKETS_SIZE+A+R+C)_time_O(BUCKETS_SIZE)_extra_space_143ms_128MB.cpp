class MyHashSet {
private:
    const int BUCKETS_SIZE = 1e5;
    vector<vector<int>> buckets;

    int getHashValue(int key) {
        return key % BUCKETS_SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(BUCKETS_SIZE);
    }
    
    void add(int key) {
        if(!contains(key)){
            buckets[getHashValue(key)].push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            vector<int>& bucket = buckets[getHashValue(key)];
            bucket.erase(find(bucket.begin(), bucket.end(), key));
        }
    }
    
    bool contains(int key) {
        vector<int>& bucket = buckets[getHashValue(key)];
        return (find(bucket.begin(), bucket.end(), key) != bucket.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */