class SmallestInfiniteSet {
private:
    const int MAX_NUM = 1000;
    set<int> numSet;

public:
    SmallestInfiniteSet() {
        for(int num = 1; num <= MAX_NUM; ++num){
            numSet.insert(num);
        }
    }
    
    int popSmallest() {
        int num = *numSet.begin();
        numSet.erase(numSet.begin());
        return num;
    }
    
    void addBack(int num) {
        numSet.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */