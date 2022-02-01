class SORTracker {
private:
    set<pair<int, string>> locationsSet;
    set<pair<int, string>>::iterator qIt;
    
public:
    SORTracker() {
        qIt = locationsSet.end();
    }
    
    void add(string name, int score) {
        set<pair<int, string>>::iterator it = locationsSet.emplace(-score, name).first;
        if(qIt == locationsSet.end() || *it < *qIt){
            --qIt;
        }
    }
    
    string get() {
        return (qIt++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */