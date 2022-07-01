class SeatManager {
private:
    set<int> availableSeats;
    
public:
    SeatManager(int n) {
        for(int seatNumber = 1; seatNumber <= n; ++seatNumber){
            availableSeats.insert(seatNumber);
        }
    }
    
    int reserve() {
        int seatNumber = *availableSeats.begin();
        availableSeats.erase(availableSeats.begin());
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */