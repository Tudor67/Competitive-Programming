class MyCalendarTwo {
private:
    map<int, int> delta;

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        delta[start] += 1;
        delta[end] -= 1;

        int activeIntervals = 0;
        for(const pair<const int, int>& P: delta){
            activeIntervals += P.second;
            if(activeIntervals >= 3){
                delta[start] -= 1;
                delta[end] += 1;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */