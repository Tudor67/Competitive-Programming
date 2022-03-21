class FreqStack {
private:
    vector<stack<int>> values;
    unordered_map<int, int> count;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        count[val] += 1;
        if(count[val] >= (int)values.size()){
            values.resize(count[val] + 1);
        }
        values[count[val]].push(val);
    }
    
    int pop() {
        int val = values.back().top();
        count[val] -= 1;
        values.back().pop();
        if(values.back().empty()){
            values.pop_back();
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