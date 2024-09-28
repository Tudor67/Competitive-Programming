class MyCalendar {
private:
    set<pair<int, int>> eventsSet;

    bool intersects(const pair<int, int>& A, const pair<int, int>& B){
        return (max(A.first, B.first) <= min(A.second, B.second));
    }

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> currEvent = {start, end - 1};
        set<pair<int, int>>::iterator it = eventsSet.lower_bound(currEvent);
        if((it != eventsSet.end() && intersects(*it, currEvent)) ||
           (it != eventsSet.begin() && intersects(*prev(it), currEvent))){
            return false;
        }
        eventsSet.insert(currEvent);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */