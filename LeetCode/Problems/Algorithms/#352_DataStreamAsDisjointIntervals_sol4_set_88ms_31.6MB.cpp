class SummaryRanges {
private:
    set<vector<int>> intervals;
    set<int> values;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(!values.count(val)){
            values.insert(val);
            int l = val;
            int r = val;
            
            set<vector<int>>::iterator it = intervals.upper_bound({val, val});
            if(it != intervals.begin()){
                set<vector<int>>::iterator prev_it = prev(it);
                if((*prev_it)[1] == val - 1){
                    l = (*prev_it)[0];
                    intervals.erase(prev_it);
                }
            }
            if(it != intervals.end()){
                if(val + 1 == (*it)[0]){
                    r = (*it)[1];
                    intervals.erase(it);
                }
            }
            
            intervals.insert({l, r});
        }
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>>(intervals.begin(), intervals.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */