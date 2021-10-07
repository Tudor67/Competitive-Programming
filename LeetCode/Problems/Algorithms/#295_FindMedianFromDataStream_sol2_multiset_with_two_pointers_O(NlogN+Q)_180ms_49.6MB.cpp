class MedianFinder {
private:
    multiset<int> data;
    multiset<int>::iterator leftMedian;
    multiset<int>::iterator rightMedian;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.insert(num);
        if((data.size() - 1) == 0){
            // Case 1: init
            leftMedian = data.begin();
            rightMedian = data.begin();
        }else if((data.size() - 1) % 2 == 0){
            // Case 2: even size
            if(*leftMedian <= num && num < *rightMedian){
                leftMedian = next(leftMedian);
                rightMedian = prev(rightMedian);
            }else if(num < *leftMedian){
                rightMedian = leftMedian;
            }else{
                leftMedian = rightMedian;
            }
        }else if((data.size() - 1) % 2 == 1){
            // Case 3: odd size
            if(num < *leftMedian){
                leftMedian = prev(leftMedian);
            }else{
                rightMedian = next(rightMedian);
            }
        }
    }
    
    double findMedian() {
        return ((double)*leftMedian + (double)*rightMedian) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */