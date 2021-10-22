class RandomizedSet {
private:
    vector<int> currentValues;
    unordered_map<int, int> idxOf;
    
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(idxOf.count(val)){
            return false;
        }
        currentValues.push_back(val);
        idxOf[val] = (int)currentValues.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!idxOf.count(val)){
            return false;
        }
        idxOf[currentValues.back()] = idxOf[val];
        currentValues[idxOf[val]] = currentValues.back();
        currentValues.pop_back();
        idxOf.erase(val);
        return true;
    }
    
    int getRandom() {
        return currentValues[rand() % currentValues.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */