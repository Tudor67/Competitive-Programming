class SmallestInfiniteSet {
private:
    const int MAX_NUM = 1000;
    vector<bool> inSet;
    int smallestNum;

public:
    SmallestInfiniteSet() {
        inSet.assign(MAX_NUM + 1, true);
        smallestNum = 1;
    }
    
    int popSmallest() {
        while(smallestNum < MAX_NUM && !inSet[smallestNum]){
            smallestNum += 1;
        }
        inSet[smallestNum] = false;
        return smallestNum;
    }
    
    void addBack(int num) {
        inSet[num] = true;
        smallestNum = min(smallestNum, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */