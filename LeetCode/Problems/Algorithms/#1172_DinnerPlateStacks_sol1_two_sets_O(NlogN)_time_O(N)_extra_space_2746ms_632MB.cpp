class DinnerPlates {
private:
    int capacity;
    vector<stack<int>> stacks;
    set<int> freeIndices;     // stack indices with 0 <= stacks[index].size() < capacity
    set<int> nonEmptyIndices; // stack indices with 1 <= stacks[index].size() <= capacity
    
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        nonEmptyIndices.insert(-1);
    }
    
    void push(int val) {
        int index = -1;
        if(freeIndices.empty()){
            index = *prev(nonEmptyIndices.end()) + 1;
            freeIndices.insert(index);
        }else{
            index = *freeIndices.begin();
        }
        
        if((int)stacks.size() <= index){
            stacks.push_back({});
        }
        
        stacks[index].push(val);
        if((int)stacks[index].size() == capacity){
            freeIndices.erase(index);
        }
        if((int)stacks[index].size() == 1){
            nonEmptyIndices.insert(index);
        }
    }
    
    int pop() {
        int maxIndex = *prev(nonEmptyIndices.end());
        return popAtStack(maxIndex);
    }
    
    int popAtStack(int index) {
        if(index < 0 || (int)stacks.size() <= index || stacks[index].empty()){
            return -1;
        }
        
        int val = stacks[index].top();
        stacks[index].pop();
        
        if((int)stacks[index].size() == capacity - 1){
            freeIndices.insert(index);
        }
        if(stacks[index].empty()){
            nonEmptyIndices.erase(index);
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