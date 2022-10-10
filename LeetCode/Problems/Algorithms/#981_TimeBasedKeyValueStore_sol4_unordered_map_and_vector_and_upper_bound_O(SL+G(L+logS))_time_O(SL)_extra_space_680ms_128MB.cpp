class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> tvOf;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tvOf[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!tvOf.count(key)){
            return "";
        }
        const vector<pair<int, string>>& TV = tvOf[key];
        auto it = upper_bound(TV.begin(), TV.end(), pair<int, string>{timestamp, "}"});
        if(it != TV.begin()){
            return prev(it)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */