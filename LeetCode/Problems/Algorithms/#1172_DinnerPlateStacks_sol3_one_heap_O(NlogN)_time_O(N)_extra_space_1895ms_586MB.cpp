class DinnerPlates {
private:
    int capacity;
    vector<stack<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> freeIndices;  // stack indices with 0 <= stacks[index].size() < capacity
    
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        int index = -1;
        if(freeIndices.empty()){
            index = stacks.size();
            freeIndices.push(index);
        }else{
            index = freeIndices.top();
        }
        
        if((int)stacks.size() <= index){
            stacks.push_back({});
        }
        
        stacks[index].push(val);
        if((int)stacks[index].size() == capacity){
            freeIndices.pop();
        }
    }
    
    int pop() {
        return popAtStack((int)stacks.size() - 1);
    }
    
    int popAtStack(int index) {
        if(index < 0 || (int)stacks.size() <= index || stacks[index].empty()){
            return -1;
        }
        
        int val = stacks[index].top();
        stacks[index].pop();
        
        if((int)stacks[index].size() == capacity - 1){
            freeIndices.push(index);
        }
        
        while(!stacks.empty() && stacks.back().empty()){
            stacks.pop_back();
        }
        
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */