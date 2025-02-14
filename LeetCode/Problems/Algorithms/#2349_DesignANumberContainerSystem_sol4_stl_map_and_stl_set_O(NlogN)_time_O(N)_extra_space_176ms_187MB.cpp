class NumberContainers {
private:
    map<int, int> indexToNum;
    set<pair<int, int>> numIndexSet;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.count(index)){
            int oldNumber = indexToNum[index];
            numIndexSet.erase({oldNumber, index});
        }
        indexToNum[index] = number;
        numIndexSet.insert({number, index});
    }
    
    int find(int number) {
        set<pair<int, int>>::iterator it = numIndexSet.lower_bound({number, -1});
        if(it == numIndexSet.end() || it->first != number){
            return -1;
        }
        return it->second;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */