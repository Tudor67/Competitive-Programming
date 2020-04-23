class MinStack {
private:
    stack<pair<int, int>> st;
    
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(st.empty()){
            st.push({x, x});
        }else{
            st.push({x, min(x, st.top().second)});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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