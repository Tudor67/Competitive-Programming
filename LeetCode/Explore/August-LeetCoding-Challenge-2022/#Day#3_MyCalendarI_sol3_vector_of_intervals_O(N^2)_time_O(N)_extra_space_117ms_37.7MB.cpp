class MyCalendar {
private:
    vector<pair<int, int>> intervals;
    
    bool isOverlapping(const pair<int, int>& A, const pair<int, int>& B){
        return max(A.first, B.first) <= min(A.second, B.second);
    }
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> newInterval = {start, end - 1};
        for(const pair<int, int>& I: intervals){
            if(isOverlapping(I, newInterval)){
                return false;
            }
        }
        intervals.push_back(newInterval);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */