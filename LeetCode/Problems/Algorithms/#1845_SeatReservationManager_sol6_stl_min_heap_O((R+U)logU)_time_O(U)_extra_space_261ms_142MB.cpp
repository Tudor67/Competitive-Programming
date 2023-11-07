class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> availHeap;
    int maxAddedSeat;

public:
    SeatManager(int n) {
        maxAddedSeat = 0;
    }
    
    int reserve() {
        if(availHeap.empty()){
            maxAddedSeat += 1;
            availHeap.push(maxAddedSeat);
        }
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