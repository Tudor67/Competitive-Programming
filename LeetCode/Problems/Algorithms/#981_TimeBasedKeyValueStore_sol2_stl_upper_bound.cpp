class TimeMap {
private:
    map<string, vector<pair<int, string>>> timestampValue;
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timestampValue[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        string answer;
        const vector<pair<int, string>>& TV = timestampValue[key];
        if(!TV.empty()){
            auto it = upper_bound(TV.begin(), TV.end(), pair<int, string>{timestamp, "}"});
            if(it != TV.begin()){
                answer = prev(it)->second;
            }
        }
        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */