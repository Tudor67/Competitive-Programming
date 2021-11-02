class FrontMiddleBackQueue {
private:
    list<int> values;
    list<int>::iterator midIt;
    
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        values.push_front(val);
        if((int)values.size() == 1){
            midIt = values.begin();
        }else if(values.size() % 2 == 1){
            midIt = prev(midIt);
        }
    }
    
    void pushMiddle(int val) {
        if(values.empty()){
            midIt = values.begin();
        }
        values.insert(midIt, val);
        if((int)values.size() == 1){
            midIt = values.begin();
        }else if(values.size() % 2 == 1){
            midIt = prev(midIt);
        }
    }
    
    void pushBack(int val) {
        values.push_back(val);
        if((int)values.size() == 1){
            midIt = values.begin();
        }else if(values.size() % 2 == 0){
            midIt = next(midIt);
        }
    }
    
    int popFront() {
        if(values.empty()){
            return -1;
        }
        int val = values.front();
        values.pop_front();
        if(!values.empty() && values.size() % 2 == 0){
            midIt = next(midIt);
        }
        return val;
    }
    
    int popMiddle() {
        if(values.empty()){
            return -1;
        }
        int val = 0;
        if(values.size() % 2 == 0){
            val = *prev(midIt);
            midIt = values.erase(prev(midIt));
        }else{
            val = *midIt;
            midIt = values.erase(midIt);
        }
        return val;
    }
    
    int popBack() {
        if(values.empty()){
            return -1;
        }
        int val = values.back();
        values.pop_back();
        if((int)values.size() == 1){
            midIt = values.begin();
        }else if(values.size() % 2 == 1){
            midIt = prev(midIt);
        }
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