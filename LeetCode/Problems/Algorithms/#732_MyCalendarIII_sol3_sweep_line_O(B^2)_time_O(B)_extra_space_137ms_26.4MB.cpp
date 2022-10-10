class MyCalendarThree {
private:
    map<int, int> diff;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        diff[start] += 1;
        diff[end] -= 1;
        int activeSegments = 0;
        int maxActiveSegments = 0;
        for(const pair<int, int>& P: diff){
            activeSegments += P.second;
            maxActiveSegments = max(maxActiveSegments, activeSegments);
        }
        return maxActiveSegments;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */