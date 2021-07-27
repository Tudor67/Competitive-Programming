class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftHeap.push(num);
        rightHeap.push(leftHeap.top());
        leftHeap.pop();
        
        if(leftHeap.size() < rightHeap.size()){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size()){
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        return leftHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */