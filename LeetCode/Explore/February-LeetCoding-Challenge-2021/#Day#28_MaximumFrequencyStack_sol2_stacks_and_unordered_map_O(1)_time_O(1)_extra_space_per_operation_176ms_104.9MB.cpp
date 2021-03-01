class FreqStack {
private:
    unordered_map<int, int> freq;
    vector<stack<int>> stacks; // stacks[f]: a stack containing elements with freq[elem] = f
                               //            elements are pushed onto the stack in the order of `push` operations
public:
    FreqStack() {}
    
    void push(int x) {
        freq[x] += 1;
        if(freq[x] >= stacks.size()){
            stacks.resize(freq[x] + 1);
        }
        stacks[freq[x]].push(x);
    }
    
    int pop() {
        int x = stacks.back().top();
        stacks.back().pop();
        if(stacks.back().empty()){
            stacks.pop_back();
        }
        freq[x] -= 1;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */