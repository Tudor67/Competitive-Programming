class MyCalendar {
private:
    using Interval = pair<int, int>;
    set<Interval> intervalsSet;
    
    bool overlap(const Interval& I1, const Interval& I2){
        return max(I1.first, I2.first) < min(I1.second, I2.second);
    }
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Interval curInterval = {start, end};
        set<Interval>::iterator it = intervalsSet.upper_bound(curInterval);
        if((it != intervalsSet.begin() && overlap(*prev(it), curInterval)) ||
           (it != intervalsSet.end() && overlap(curInterval, *it))){
            return false;
        }
        intervalsSet.insert(curInterval);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */