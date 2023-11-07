class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> availHeap;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; ++i){
            availHeap.push(i);
        }
    }
    
    int reserve() {
        int seatNumber = availHeap.top();
        availHeap.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */