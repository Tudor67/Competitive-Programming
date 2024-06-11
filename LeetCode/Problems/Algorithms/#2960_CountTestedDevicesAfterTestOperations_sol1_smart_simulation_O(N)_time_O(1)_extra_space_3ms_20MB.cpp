class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int testedDevices = 0;
        for(int bp: batteryPercentages){
            if(bp - testedDevices > 0){
                testedDevices += 1;
            }
        }
        return testedDevices;
    }
};