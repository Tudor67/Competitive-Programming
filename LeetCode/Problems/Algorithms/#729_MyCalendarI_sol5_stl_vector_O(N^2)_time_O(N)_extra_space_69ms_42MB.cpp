class MyCalendar {
private:
    vector<pair<int, int>> events;

    bool intersects(const pair<int, int>& A, const pair<int, int>& B){
        return (max(A.first, B.first) <= min(A.second, B.second));
    }

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> currEvent = {start, end - 1};

        int i = 0;
        while(i < (int)events.size() && events[i].second < currEvent.first){
            i += 1;
        }

        if(i < (int)events.size() && intersects(events[i], currEvent)){
            return false;
        }

        events.insert(events.begin() + i, currEvent);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */