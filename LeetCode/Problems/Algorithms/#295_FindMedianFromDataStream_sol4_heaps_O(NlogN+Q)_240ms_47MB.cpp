class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftMaxHeap.push(num);
        
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();
        
        if(leftMaxHeap.size() < rightMinHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() > rightMinHeap.size()){
            return leftMaxHeap.top();
        }
        return ((double)leftMaxHeap.top() + (double)rightMinHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */