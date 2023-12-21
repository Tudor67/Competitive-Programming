class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCities;
        for(const vector<string>& P: paths){
            string startCity = P[0];
            startCities.insert(startCity);
        }

        for(const vector<string>& P: paths){
            string destCity = P[1];
            if(!startCities.count(destCity)){
                return destCity;
            }
        }

        return "";
    }
};