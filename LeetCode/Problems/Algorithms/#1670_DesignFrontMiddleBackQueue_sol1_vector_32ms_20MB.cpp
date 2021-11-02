class FrontMiddleBackQueue {
private:
    vector<int> values;
    
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        values.insert(values.begin(), val);
    }
    
    void pushMiddle(int val) {
        values.insert(values.begin() + values.size() / 2, val);
    }
    
    void pushBack(int val) {
        values.push_back(val);
    }
    
    int popFront() {
        if(values.empty()){
            return -1;
        }
        int val = values.front();
        values.erase(values.begin());
        return val;
    }
    
    int popMiddle() {
        if(values.empty()){
            return -1;
        }
        int val = values[((int)values.size() - 1) / 2];
        values.erase(values.begin() + ((int)values.size() - 1) / 2);
        return val;
    }
    
    int popBack() {
        if(values.empty()){
            return -1;
        }
        int val = values.back();
        values.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */