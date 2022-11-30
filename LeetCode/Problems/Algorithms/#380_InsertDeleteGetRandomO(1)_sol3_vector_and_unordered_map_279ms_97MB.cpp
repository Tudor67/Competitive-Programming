class RandomizedSet {
private:
    vector<int> values;
    unordered_map<int, int> posOf;
    
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(posOf.count(val)){
            return false;
        }
        values.push_back(val);
        posOf[val] = (int)values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!posOf.count(val)){
            return false;
        }
        values[posOf[val]] = values.back();
        posOf[values.back()] = posOf[val];
        values.pop_back();
        posOf.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */