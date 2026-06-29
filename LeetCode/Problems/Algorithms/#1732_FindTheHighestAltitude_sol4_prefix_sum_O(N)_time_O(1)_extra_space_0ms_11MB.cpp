class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currAltitude = 0;
        for(int g: gain){
            currAltitude += g;
            maxAltitude = max(maxAltitude, currAltitude);
        }
        return maxAltitude;
    }
};