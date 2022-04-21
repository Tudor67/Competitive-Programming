class MyHashSet {
private:
    static const int MODULO = 77977;
    vector<vector<int>> v;
    
    int getHashValue(int key){
        return (key % MODULO);
    }
    
public:
    MyHashSet() {
        v.resize(MODULO);
    }
    
    void add(int key) {
        if(!contains(key)){
            v[getHashValue(key)].push_back(key);
        }
    }
    
    void remove(int key) {
        int hashValue = getHashValue(key);
        for(int j = 0; j < (int)v[hashValue].size(); ++j){
            if(key == v[hashValue][j]){
                swap(v[hashValue][j], v[hashValue].back());
                v[hashValue].pop_back();
                break;
            }
        }
    }
    
    bool contains(int key) {
        int hashValue = getHashValue(key);
        for(int j = 0; j < (int)v[hashValue].size(); ++j){
            if(key == v[hashValue][j]){
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