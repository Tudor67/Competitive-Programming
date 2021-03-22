class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> startStationAndTime;
    unordered_map<string, pair<double, double>> timeSumAndCount;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        startStationAndTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStationName = startStationAndTime[id].first;
        int startTime = startStationAndTime[id].second;
        string tripName = startStationName + "#" + stationName;
        timeSumAndCount[tripName].first += t - startTime;
        timeSumAndCount[tripName].second += 1;
        startStationAndTime.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tripName = startStation + "#" + endStation;
        return timeSumAndCount[tripName].first / timeSumAndCount[tripName].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */