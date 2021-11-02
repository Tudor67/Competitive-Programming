class RandomizedCollection {
private:
    vector<int> currentValues;
    unordered_map<int, unordered_set<int>> indicesOf;
    
public:
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        currentValues.push_back(val);
        indicesOf[val].insert((int)currentValues.size() - 1);
        return ((int)indicesOf[val].size() == 1);
    }
    
    bool remove(int val) {
        if(!indicesOf.count(val)){
            return false;
        }
        
        if(currentValues.back() == val){
            int valIdx = (int)currentValues.size() - 1;
            indicesOf[val].erase(valIdx);
            currentValues.pop_back();
        }else{
            int valIdx = *indicesOf[val].begin();
            int newVal = currentValues.back();
            int newValIdx = (int)currentValues.size() - 1;

            indicesOf[newVal].erase(newValIdx);
            indicesOf[newVal].insert(valIdx);
            currentValues[valIdx] = newVal;

            indicesOf[val].erase(valIdx);
            currentValues.pop_back();
        }
        
        if(indicesOf[val].empty()){
            indicesOf.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        return currentValues[rand() % currentValues.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */