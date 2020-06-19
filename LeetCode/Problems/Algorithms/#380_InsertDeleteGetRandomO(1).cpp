class RandomizedSet {
private:
    unordered_map<int, int> pos;
    vector<int> current_values;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool was_in_set = false;
        if(pos.count(val)){
            was_in_set = true;
        }else{
            pos[val] = current_values.size();
            current_values.push_back(val);
        }
        return !was_in_set;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool was_in_set = false;
        if(pos.count(val)){
            was_in_set = true;
            pos[current_values.back()] = pos[val];
            current_values[pos[val]] = current_values.back();
            pos.erase(val);
            current_values.pop_back();
        }
        return was_in_set;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return current_values[rand() % current_values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */