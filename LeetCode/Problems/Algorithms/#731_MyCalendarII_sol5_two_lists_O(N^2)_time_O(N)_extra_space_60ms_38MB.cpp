class MyCalendarTwo {
private:
    using Interval = pair<int, int>;
    vector<Interval> intervals1;
    vector<Interval> intervals2;

    Interval computeIntersection(const Interval& A, const Interval& B){
        return {max(A.first, B.first), min(A.second, B.second)};
    }

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        Interval currInterval = {start, end - 1};

        for(const Interval& I: intervals2){
            Interval intersection = computeIntersection(I, currInterval);
            if(intersection.first <= intersection.second){
                return false;
            }
        }

        for(const Interval& I: intervals1){
            Interval intersection = computeIntersection(I, currInterval);
            if(intersection.first <= intersection.second){
                intervals2.push_back(intersection);
            }
        }
        intervals1.push_back(currInterval);

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */