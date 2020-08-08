class MyHashSet {
private:
    static const int MODULO = 666013;
    vector<vector<int>> v;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v.resize(MODULO);
    }
    
    void add(int key) {
        if(!contains(key)){
            int hash = key % MODULO;
            v[hash].push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            int hash = key % MODULO;
            int pos = find(v[hash].begin(), v[hash].end(), key) - v[hash].begin();
            v[hash][pos] = v[hash].back();
            v[hash].pop_back();
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = key % MODULO;
        for(int elem: v[hash]){
            if(elem == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */