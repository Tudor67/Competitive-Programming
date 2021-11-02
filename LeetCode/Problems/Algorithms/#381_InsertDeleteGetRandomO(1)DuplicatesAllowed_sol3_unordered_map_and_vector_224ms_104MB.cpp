class RandomizedCollection {
private:
    vector<pair<int, int>> v; // v[i] = {val, index of v[i] in vector indicesOf[val]};
    unordered_map<int, vector<int>> indicesOf; // indicesOf[val]: a vector with indices of val in vector v;
                                               // indicesOf[v[i].first][v[i].second] == i;
    
public:
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        int valIdxInV = v.size();
        indicesOf[val].push_back(valIdxInV);
        
        int valIdxInMap = (int)indicesOf[val].size() - 1;
        v.push_back({val, valIdxInMap});
        
        return ((int)indicesOf[val].size() == 1);
    }
    
    bool remove(int val) {
        if(!indicesOf.count(val)){
            return false;
        }
        
        int valIdxInV = indicesOf[val].back();
        int newVal = v.back().first;
        int newValIdxInMap = v.back().second;
        
        v[valIdxInV] = v.back();
        v.pop_back();
        
        indicesOf[val].pop_back();
        indicesOf[newVal][newValIdxInMap] = valIdxInV;
        
        if(indicesOf[val].empty()){
            indicesOf.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */