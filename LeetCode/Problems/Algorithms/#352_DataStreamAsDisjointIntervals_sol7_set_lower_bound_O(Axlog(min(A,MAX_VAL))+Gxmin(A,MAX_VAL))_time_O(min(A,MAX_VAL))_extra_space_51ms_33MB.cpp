class SummaryRanges {
private:
    set<pair<int, int>> intervalsSet;

public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        set<pair<int, int>>::iterator it = intervalsSet.upper_bound({value, value});

        // Case 1: merge prev(it) and it with the current value
        if(it != intervalsSet.begin() && it != intervalsSet.begin()){
            if(prev(it)->second + 1 == value && value + 1 == it->first){
                pair<int, int> mergedInterval = {prev(it)->first, it->second};
                intervalsSet.erase(prev(it), next(it));
                intervalsSet.insert(mergedInterval);
                return;
            }
        }

        // Case 2: merge the current value with it
        if(it != intervalsSet.end() && value + 1 == it->first){
            pair<int, int> mergedInterval = {value, it->second};
            intervalsSet.erase(it);
            intervalsSet.insert(mergedInterval);
            return;
        }

        // Case 3: merge prev(it) with the current value
        if(it != intervalsSet.begin() && prev(it)->second + 1 == value){
            pair<int, int> mergedInterval = {prev(it)->first, value};
            intervalsSet.erase(prev(it));
            intervalsSet.insert(mergedInterval);
            return;
        }

        // Case 4: current value creates a new interval [value, value]
        if((it == intervalsSet.begin() || prev(it)->second + 1 < value) &&
           (it == intervalsSet.end() || value + 1 < it->first)){
               intervalsSet.insert({value, value});
               return;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(const pair<int, int>& I: intervalsSet){
            res.push_back({I.first, I.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */