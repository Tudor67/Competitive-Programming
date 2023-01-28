class SummaryRanges {
private:
    const int MAX_VAL = 1e4;
    set<int> valSet;

public:
    SummaryRanges() {

    }
    
    void addNum(int value) {
        valSet.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(int val: valSet){
            if(res.empty() || res.back()[1] + 1 < val){
                res.push_back({val, val});
            }else{
                res.back()[1] = val;
            }
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