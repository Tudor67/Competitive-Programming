class MyCalendarThree {
private:
    map<int, int> count;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        count[start] += 1;
        count[end] -= 1;
        int maxK = 1;
        int k = 0;
        for(const pair<int, int>& P: count){
            k += P.second;
            maxK = max(k, maxK);
        }
        return maxK;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */