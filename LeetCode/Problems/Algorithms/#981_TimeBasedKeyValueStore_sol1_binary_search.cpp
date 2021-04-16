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
            int l = 0;
            int r = (int)TV.size() - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(TV[mid].first <= timestamp){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(TV[r].first <= timestamp){
                answer = TV[r].second;
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