class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        const int ROWS = bank.size();
        const int COLS = bank[0].size();

        int res = 0;
        int prevDevices = 0;
        for(string& bankRow: bank){
            int currDevices = count(bankRow.begin(), bankRow.end(), '1');
            if(currDevices >= 1){
                res += prevDevices * currDevices;
                prevDevices = currDevices;
            }
        }

        return res;
    }
};