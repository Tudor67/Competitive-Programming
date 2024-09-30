class AllOne {
private:
    unordered_map<string, int> freqOf;
    set<pair<int, string>> freqStrSet;

public:
    AllOne() {
        
    }
    
    void inc(string key) {
        freqStrSet.erase({freqOf[key], key});
        freqOf[key] += 1;
        freqStrSet.insert({freqOf[key], key});
    }
    
    void dec(string key) {
        freqStrSet.erase({freqOf[key], key});
        freqOf[key] -= 1;
        if(freqOf[key] == 0){
            freqOf.erase(key);
        }else{
            freqStrSet.insert({freqOf[key], key});
        }
    }
    
    string getMaxKey() {
        if(freqStrSet.empty()){
            return "";
        }
        return freqStrSet.rbegin()->second;
    }
    
    string getMinKey() {
        if(freqStrSet.empty()){
            return "";
        }
        return freqStrSet.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */