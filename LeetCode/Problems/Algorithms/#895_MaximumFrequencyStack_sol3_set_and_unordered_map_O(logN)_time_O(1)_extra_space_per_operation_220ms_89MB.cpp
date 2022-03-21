class FreqStack {
private:
    int currentTime;
    unordered_map<int, vector<int>> timesOf;
    set<tuple<int, int, int>> freqTimeVal;
    
public:
    FreqStack() {
        currentTime = 0;
    }
    
    void push(int val) {
        if(timesOf.count(val)){
            freqTimeVal.erase({timesOf[val].size(), timesOf[val].back(), val});
        }
        currentTime += 1;
        timesOf[val].push_back(currentTime);
        freqTimeVal.emplace(timesOf[val].size(), timesOf[val].back(), val);
    }
    
    int pop() {
        int val = get<2>(*freqTimeVal.rbegin());
        freqTimeVal.erase({timesOf[val].size(), timesOf[val].back(), val});
        timesOf[val].pop_back();
        if(timesOf[val].empty()){
            timesOf.erase(val);
        }else{
            freqTimeVal.emplace(timesOf[val].size(), timesOf[val].back(), val);
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */