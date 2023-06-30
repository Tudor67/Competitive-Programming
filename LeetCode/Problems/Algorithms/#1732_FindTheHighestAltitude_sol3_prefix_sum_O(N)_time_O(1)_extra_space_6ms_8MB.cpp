class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int altitude = 0;
        for(int g: gain){
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }
        return maxAltitude;
    }
};