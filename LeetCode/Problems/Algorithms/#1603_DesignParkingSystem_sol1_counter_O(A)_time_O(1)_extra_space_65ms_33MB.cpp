class ParkingSystem {
private:
    vector<int> availableSlots;

public:
    ParkingSystem(int big, int medium, int small) {
        availableSlots = {0, big, medium, small};
    }
    
    bool addCar(int carType) {
        if(availableSlots[carType] >= 1){
            availableSlots[carType] -= 1;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */