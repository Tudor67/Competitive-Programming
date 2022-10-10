class TimeMap {
private:
    set<tuple<string, int, string>> keyTimestampValueSet;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimestampValueSet.emplace(key, timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = keyTimestampValueSet.upper_bound({key, timestamp, "}"});
        if(it != keyTimestampValueSet.begin()){
            if(std::get<0>(*prev(it)) == key && std::get<1>(*prev(it)) <= timestamp){
                return std::get<2>(*prev(it));
            }
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