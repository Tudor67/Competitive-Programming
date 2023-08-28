class MyStack {
private:
    queue<int> q;

    void shiftQueue(int k){
        for(int i = 1; i <= k; ++i){
            q.push(q.front());
            q.pop();
        }
    }

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        shiftQueue((int)q.size() - 1);
        int topElem = q.front();
        q.pop();
        return topElem;
    }
    
    int top() {
        shiftQueue((int)q.size() - 1);
        int topElem = q.front();
        shiftQueue(1);
        return topElem;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */