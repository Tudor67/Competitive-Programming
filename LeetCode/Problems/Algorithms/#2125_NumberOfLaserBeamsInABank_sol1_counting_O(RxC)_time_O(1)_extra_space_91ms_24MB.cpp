class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        const int ROWS = bank.size();
        const int COLS = bank[0].size();

        int res = 0;
        int prevDevices = 0;
        for(const string& ROW_STR: bank){
            int devices = count(ROW_STR.begin(), ROW_STR.end(), '1');
            if(devices >= 1){
                res += prevDevices * devices;
                prevDevices = devices;
            }
        }

        return res;
    }
};