class MyCalendarThree {
private:
    const int START_EVENT = 1;
    const int END_EVENT = 0;
    multiset<pair<int, int>> events;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        events.insert({start, START_EVENT});
        events.insert({end, END_EVENT});
        int maxK = 1;
        int k = 0;
        for(const pair<int, int>& EVENT: events){
            int eventType = EVENT.second;
            if(eventType == END_EVENT){
                k -= 1;
            }else{
                k += 1;
                maxK = max(k, maxK);
            }
        }
        return maxK;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */