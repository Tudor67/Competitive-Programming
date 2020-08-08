class MyHashSet {
private:
    bitset<1000001> vis;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
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