class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> availableSeats;
    
public:
    SeatManager(int n) {
        for(int seatNumber = 1; seatNumber <= n; ++seatNumber){
            availableSeats.push(seatNumber);
        }
    }
    
    int reserve() {
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