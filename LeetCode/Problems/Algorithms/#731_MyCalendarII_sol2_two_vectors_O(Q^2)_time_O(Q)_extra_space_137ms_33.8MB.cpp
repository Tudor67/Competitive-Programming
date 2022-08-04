class MyCalendarTwo {
private:
    vector<pair<int, int>> initialIntervals;
    vector<pair<int, int>> overlappingIntervals;
    
    pair<int, int> computeOverlap(const pair<int, int>& A, const pair<int, int>& B){
        return {max(A.first, B.first), min(A.second, B.second)};
    }
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> newInterval = {start, end - 1};
        for(const pair<int, int>& INTERVAL: overlappingIntervals){
            pair<int, int> overlap = computeOverlap(INTERVAL, newInterval);
            if(overlap.first <= overlap.second){
                return false;
            }
        }
        
        for(const pair<int, int>& INTERVAL: initialIntervals){
            pair<int, int> overlap = computeOverlap(INTERVAL, newInterval);
            if(overlap.first <= overlap.second){
                overlappingIntervals.push_back(overlap);
            }
        }
        initialIntervals.push_back(newInterval);
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */