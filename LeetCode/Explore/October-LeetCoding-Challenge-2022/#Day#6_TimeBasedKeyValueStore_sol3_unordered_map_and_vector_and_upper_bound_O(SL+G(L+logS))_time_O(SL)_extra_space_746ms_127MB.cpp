class TimeMap {
private:
    unordered_map<string, vector<int>> timestampsOf;
    unordered_map<string, vector<string>> valuesOf;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timestampsOf[key].push_back(timestamp);
        valuesOf[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(!timestampsOf.count(key)){
            return "";
        }
        const vector<int>& T = timestampsOf[key];
        int pos = upper_bound(T.begin(), T.end(), timestamp) - T.begin() - 1;
        if(pos >= 0){
            return valuesOf[key][pos];
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