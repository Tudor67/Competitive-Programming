class FreqStack {
private:
    int currentTime;
    priority_queue<tuple<int, int, int>> maxHeap;
    unordered_map<int, int> count;
    
public:
    FreqStack() {
        currentTime = 0;
    }
    
    void push(int val) {
        count[val] += 1;
        currentTime += 1;
        maxHeap.emplace(count[val], currentTime, val);
    }
    
    int pop() {
        int val = get<2>(maxHeap.top());
        maxHeap.pop();
        count[val] -= 1;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */