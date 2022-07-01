class DinnerPlates {
private:
    int capacity;
    vector<stack<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> freeIndices;  // stack indices with 0 <= stacks[index].size() < capacity
    priority_queue<int, vector<int>, less<int>> nonEmptyIndices; // stack indices with 1 <= stacks[index].size() <= capacity
    
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        nonEmptyIndices.push(-1);
    }
    
    void push(int val) {
        int index = -1;
        if(freeIndices.empty()){
            index = nonEmptyIndices.top() + 1;
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
        if((int)stacks[index].size() == 1){
            nonEmptyIndices.push(index);
        }
    }
    
    int pop() {
        while((int)nonEmptyIndices.size() >= 2 && stacks[nonEmptyIndices.top()].empty()){
            nonEmptyIndices.pop();
        }
        int maxIndex = nonEmptyIndices.top();
        return popAtStack(maxIndex);
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