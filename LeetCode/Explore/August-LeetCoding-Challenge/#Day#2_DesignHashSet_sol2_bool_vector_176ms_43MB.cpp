class MyHashSet {
private:
    static const int MAX_VAL = 1e6;
    vector<bool> vis;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        vis.resize(MAX_VAL + 1, false);
    }
    
    void add(int key) {
        vis[key] = true;
    }
    
    void remove(int key) {
        vis[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vis[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */