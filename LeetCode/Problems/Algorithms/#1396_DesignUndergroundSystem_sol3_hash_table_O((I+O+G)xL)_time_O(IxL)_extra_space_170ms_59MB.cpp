class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> idToStartStationAndTime;
    unordered_map<string, pair<double, int>> tripToSumAndCount;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idToStartStationAndTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = idToStartStationAndTime[id].first;
        int startTime = idToStartStationAndTime[id].second;
        idToStartStationAndTime.erase(id);

        string tripName = startStation + "#" + stationName;
        int tripTime = t - startTime;

        tripToSumAndCount[tripName].first += tripTime;
        tripToSumAndCount[tripName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tripName = startStation + "#" + endStation;
        return tripToSumAndCount[tripName].first / tripToSumAndCount[tripName].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */