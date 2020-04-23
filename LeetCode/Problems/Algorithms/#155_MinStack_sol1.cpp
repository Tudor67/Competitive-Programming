class MinStack {
private:
    int n;
    vector<int> v;
    vector<int> prefix_min;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        this->n = 0;
    }
    
    void push(int x) {
        ++n;
        v.push_back(x);
        prefix_min.push_back(x);
        if(n >= 2){
            prefix_min[n - 1] = min(prefix_min[n - 2], prefix_min[n - 1]);
        }
    }
    
    void pop() {
        if(n > 0){
            --n;
            v.pop_back();
            prefix_min.pop_back();
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return prefix_min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */