class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> availableSeats;
    int maxReservedSeat;
    
public:
    SeatManager(int n) {
        maxReservedSeat = 0;
    }
    
    int reserve() {
        if(availableSeats.empty()){
            maxReservedSeat += 1;
            return maxReservedSeat;
        }
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */