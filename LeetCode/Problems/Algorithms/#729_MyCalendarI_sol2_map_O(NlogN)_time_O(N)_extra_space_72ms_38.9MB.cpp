class MyCalendar {
private:
    using Interval = pair<int, int>;
    map<int, int> endOf;
    
    bool overlap(const Interval& I1, const Interval& I2){
        return max(I1.first, I2.first) < min(I1.second, I2.second);
    }
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Interval curInterval = {start, end};
        map<int, int>::iterator it = endOf.upper_bound(curInterval.first);
        if((it != endOf.begin() && overlap(*prev(it), curInterval)) ||
           (it != endOf.end() && overlap(curInterval, *it))){
            return false;
        }
        endOf[curInterval.first] = curInterval.second;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */