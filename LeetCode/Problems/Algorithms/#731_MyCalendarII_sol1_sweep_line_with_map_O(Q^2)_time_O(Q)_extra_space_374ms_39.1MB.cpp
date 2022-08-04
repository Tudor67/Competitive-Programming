class MyCalendarTwo {
private:
    map<int, int> newSegmentsAt;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bool isPossible = true;
        newSegmentsAt[start] += 1;
        newSegmentsAt[end] -= 1;
        
        int activeSegments = 0;
        for(const pair<int, int>& P: newSegmentsAt){
            int pos = P.first;
            int newSegments = P.second;
            activeSegments += newSegments;
            if(start <= pos && pos < end && activeSegments >= 3){
                isPossible = false;
                break;
            }
        }
        
        if(!isPossible){
            newSegmentsAt[start] -= 1;
            newSegmentsAt[end] += 1;
        }
        
        return isPossible;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */