class FrontMiddleBackQueue {
private:
    deque<int> l;
    deque<int> r;
    
    void normalize(){
        if(l.size() < r.size()){
            l.push_back(r.front());
            r.pop_front();
        }else if((int)l.size() - (int)r.size() >= 2){
            r.push_front(l.back());
            l.pop_back();
        }
    }
    
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        l.push_front(val);
        normalize();
    }
    
    void pushMiddle(int val) {
        if((l.size() + r.size()) % 2 == 1){
            r.push_front(l.back());
            l.pop_back();
        }
        l.push_back(val);
    }
    
    void pushBack(int val) {
        r.push_back(val);
        normalize();
    }
    
    int popFront() {
        if(l.empty()){
            return -1;
        }
        int val = l.front();
        l.pop_front();
        normalize();
        return val;
    }
    
    int popMiddle() {
        if(l.empty()){
            return -1;
        }
        int val = l.back();
        l.pop_back();
        normalize();
        return val;
    }
    
    int popBack() {
        if(l.empty()){
            return -1;
        }
        int val = 0;
        if(r.empty()){
            val = l.back();
            l.pop_back();
        }else{
            val = r.back();
            r.pop_back();
        }
        normalize();
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