class AllOne {
private:
    unordered_map<string, int> strToFreq;
    unordered_map<string, list<string>::iterator> strToIterator;
    vector<list<string>> freqToStrs;
    int minFreq;
    int maxFreq;

public:
    AllOne() {
        minFreq = 1;
        maxFreq = 1;
    }
    
    void inc(string key) {
        int freq = strToFreq[key];

        minFreq = min(minFreq, freq + 1);
        maxFreq = max(maxFreq, freq + 1);
        if(freq == minFreq && (int)freqToStrs[freq].size() == 1){
            minFreq += 1;
        }

        if(freq >= 1){
            freqToStrs[freq].erase(strToIterator[key]);
        }
        
        if(freq + 1 >= (int)freqToStrs.size()){
            freqToStrs.resize(freq + 2);
        }

        freqToStrs[freq + 1].push_back(key);
        strToIterator[key] = prev(freqToStrs[freq + 1].end());
        strToFreq[key] = freq + 1;
    }
    
    void dec(string key) {
        int freq = strToFreq[key];

        if(freq == minFreq && (int)freqToStrs[freq].size() == 1){
            minFreq -= 1;
            if(minFreq == 0){
                minFreq = 2;
                while(minFreq < maxFreq && freqToStrs[minFreq].empty()){
                    minFreq += 1;
                }
            }
        }

        if(freq == maxFreq && (int)freqToStrs[freq].size() == 1){
            maxFreq -= 1;
        }

        freqToStrs[freq].erase(strToIterator[key]);

        if(freq == 1){
            strToFreq.erase(key);
            strToIterator.erase(key);
        }else{
            freqToStrs[freq - 1].push_back(key);
            strToIterator[key] = prev(freqToStrs[freq - 1].end());
            strToFreq[key] = freq - 1;
        }
    }
    
    string getMaxKey() {
        if(strToFreq.empty()){
            return "";
        }
        return freqToStrs[maxFreq].back();
    }
    
    string getMinKey() {
        if(strToFreq.empty()){
            return "";
        }
        return freqToStrs[minFreq].back();
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