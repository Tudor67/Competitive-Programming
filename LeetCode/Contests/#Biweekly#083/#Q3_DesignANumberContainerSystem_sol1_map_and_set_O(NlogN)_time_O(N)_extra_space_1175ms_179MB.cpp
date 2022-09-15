class NumberContainers {
private:
    map<int, int> valueAt;
    map<int, set<int>> indicesOf;
    
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(valueAt.count(index)){
            int prevNumber = valueAt[index];
            indicesOf[prevNumber].erase(index);
        }
        valueAt[index] = number;
        indicesOf[number].insert(index);
    }
    
    int find(int number) {
        if(indicesOf.count(number) && !indicesOf[number].empty()){
            return *indicesOf[number].begin();
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