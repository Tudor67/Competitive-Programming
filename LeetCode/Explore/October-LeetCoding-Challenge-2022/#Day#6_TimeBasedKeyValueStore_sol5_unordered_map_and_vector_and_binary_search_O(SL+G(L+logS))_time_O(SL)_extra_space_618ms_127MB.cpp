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
            return TV[r].second;
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