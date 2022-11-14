class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        rightHeap.push(num);
        leftHeap.push(rightHeap.top());
        rightHeap.pop();
        if((int)leftHeap.size() > (int)rightHeap.size() + 1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
    }
    
    double findMedian() {
        if((leftHeap.size() + rightHeap.size()) % 2 == 1){
            return leftHeap.top();
        }
        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */