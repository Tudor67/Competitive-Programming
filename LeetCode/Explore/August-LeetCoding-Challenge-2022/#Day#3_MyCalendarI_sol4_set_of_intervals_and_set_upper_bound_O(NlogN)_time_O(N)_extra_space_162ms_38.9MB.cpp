class MyCalendar {
private:
    set<pair<int, int>> intervalsSet;
    
    bool isOverlapping(const pair<int, int>& A, const pair<int, int>& B){
        return max(A.first, B.first) <= min(A.second, B.second);
    }
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> newInterval = {start, end - 1};
        set<pair<int, int>>::iterator it = intervalsSet.upper_bound(newInterval);
        if(it != intervalsSet.end() && isOverlapping(*it, newInterval)){
            return false;
        }
        if(it != intervalsSet.begin() && isOverlapping(*prev(it), newInterval)){
            return false;
        }
        intervalsSet.insert(newInterval);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */