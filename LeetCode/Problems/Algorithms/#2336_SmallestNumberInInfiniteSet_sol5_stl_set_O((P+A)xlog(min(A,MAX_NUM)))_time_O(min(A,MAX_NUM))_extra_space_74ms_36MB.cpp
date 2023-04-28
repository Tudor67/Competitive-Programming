class SmallestInfiniteSet {
private:
    set<int> numSet;
    int maxInsertedNum;

public:
    SmallestInfiniteSet() {
        maxInsertedNum = 0;
    }
    
    int popSmallest() {
        if(numSet.empty()){
            maxInsertedNum += 1;
            return maxInsertedNum;
        }
        int num = *numSet.begin();
        numSet.erase(numSet.begin());
        return num;
    }
    
    void addBack(int num) {
        if(num <= maxInsertedNum){
            numSet.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */