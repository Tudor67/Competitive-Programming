class NumberContainers {
private:
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    map<int, int> indexToNum;
    map<int, MinHeap> numToIndices;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indexToNum[index] = number;
        numToIndices[number].push(index);
    }
    
    int find(int number) {
        MinHeap& h = numToIndices[number];
        while(!h.empty() && indexToNum[h.top()] != number){
            h.pop();
        }
        if(h.empty()){
            numToIndices.erase(number);
            return -1;
        }
        return h.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */