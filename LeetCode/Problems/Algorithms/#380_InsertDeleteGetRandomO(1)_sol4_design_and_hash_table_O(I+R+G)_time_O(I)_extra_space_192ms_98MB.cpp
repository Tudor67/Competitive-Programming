class RandomizedSet {
private:
    vector<int> values;
    unordered_map<int, int> indexOf;

public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(indexOf.count(val)){
            return false;
        }
        values.push_back(val);
        indexOf[val] = (int)values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(indexOf.count(val)){
            values[indexOf[val]] = values.back();
            indexOf[values.back()] = indexOf[val];
            values.pop_back();
            indexOf.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randIndex = rand() % values.size();
        return values[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */