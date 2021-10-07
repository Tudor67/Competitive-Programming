class MedianFinder {
private:
    multiset<int> leftValues;
    multiset<int> rightValues;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!leftValues.empty() && num <= *leftValues.rbegin()){
            leftValues.insert(num);
        }else{
            rightValues.insert(num);
        }
        
        if(leftValues.size() > rightValues.size()){
            while(leftValues.size() > rightValues.size()){
                rightValues.insert(*prev(leftValues.end()));
                leftValues.erase(prev(leftValues.end()));
            }
        }else{
            while(rightValues.size() > leftValues.size()){
                leftValues.insert(*rightValues.begin());
                rightValues.erase(rightValues.begin());
            }
        }
    }
    
    double findMedian() {
        double median;
        if(leftValues.size() > rightValues.size()){
            median = *leftValues.rbegin();
        }else if(rightValues.size() > leftValues.size()){
            median = *rightValues.begin();
        }else{
            median = ((double)*leftValues.rbegin() + (double)*rightValues.begin()) / 2.0;
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