class RangeModule {
private:
    map<int, int> rangeEnd;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        if(it != rangeEnd.begin() && max(left, prev(it)->first) <= min(right, prev(it)->second)){
            it = prev(it);
        }
        while(it != rangeEnd.end() && it->first <= right){
            left = min(it->first, left);
            right = max(it->second, right);
            it = rangeEnd.erase(it);
        }
        rangeEnd[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        return (it != rangeEnd.begin() && right <= prev(it)->second);
    }
    
    void removeRange(int left, int right) {
        auto it = rangeEnd.upper_bound(left);
        if(it != rangeEnd.begin() && max(left, prev(it)->first) < min(right, prev(it)->second)){
            it = prev(it);
        }
        vector<pair<int, int>> newRanges;
        while(it != rangeEnd.end() && it->first < right){
            if(it->first < left){
                newRanges.emplace_back(it->first, left);
            }
            if(right < it->second){
                newRanges.emplace_back(right, it->second);
            }
            it = rangeEnd.erase(it);
        }
        for(const pair<int, int>& RANGE: newRanges){
            rangeEnd[RANGE.first] = RANGE.second;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */