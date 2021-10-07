class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!maxHeap.empty() && num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        
        if(maxHeap.size() > minHeap.size()){
            while(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }else{
            while(maxHeap.size() < minHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        double median;
        if(maxHeap.size() > minHeap.size()){
            median = maxHeap.top();
        }else if(maxHeap.size() < minHeap.size()){
            median = minHeap.top();
        }else{
            median = ((double)minHeap.top() + (double)maxHeap.top()) / 2.0;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */