class NumberContainers {
private:
    map<int, int> valueAt;
    map<int, priority_queue<int, vector<int>, greater<int>>> indicesOf;
    
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        valueAt[index] = number;
        indicesOf[number].push(index);
    }
    
    int find(int number) {
        if(indicesOf.count(number)){
            priority_queue<int, vector<int>, greater<int>>& minHeap = indicesOf[number];
            while(!minHeap.empty() && valueAt[minHeap.top()] != number){
                minHeap.pop();
            }
            if(!minHeap.empty()){
                return minHeap.top();
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */