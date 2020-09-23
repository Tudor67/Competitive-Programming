class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int MAX_LOCATION = 1000;
        vector<int> passengersAt(MAX_LOCATION + 1, 0);
        for(const vector<int>& V: trips){
            passengersAt[V[1]] += V[0];
            passengersAt[V[2]] -= V[0];
        }
        
        bool ok = true;
        int currentEmptySeats = capacity;
        for(int location = 0; location <= MAX_LOCATION; ++location){
            currentEmptySeats -= passengersAt[location];
            if(currentEmptySeats < 0){
                ok = false;
                break;
            }
        }
        
        return ok;
    }
};