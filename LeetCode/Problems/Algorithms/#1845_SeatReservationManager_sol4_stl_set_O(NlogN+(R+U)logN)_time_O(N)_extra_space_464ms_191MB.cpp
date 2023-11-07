class SeatManager {
private:
    set<int> availSet;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; ++i){
            availSet.insert(i);
        }
    }
    
    int reserve() {
        int seatNumber = *availSet.begin();
        availSet.erase(availSet.begin());
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        availSet.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */