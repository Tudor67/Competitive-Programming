class NumberContainers {
private:
    map<int, int> indexToNum;
    map<int, set<int>> numToIndices;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.count(index)){
            int oldNumber = indexToNum[index];
            numToIndices[oldNumber].erase(index);
            if(numToIndices[oldNumber].empty()){
                numToIndices.erase(oldNumber);
            }
        }
        indexToNum[index] = number;
        numToIndices[number].insert(index);
    }
    
    int find(int number) {
        if(!numToIndices.count(number)){
            return -1;
        }
        return *numToIndices[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */