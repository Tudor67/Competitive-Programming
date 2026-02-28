class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<string>> bitsToHours(4);
        for(unsigned int h = 0; h < 12; ++h){
            bitsToHours[popcount(h)].push_back(to_string(h));
        }

        vector<vector<string>> bitsToMinutes(6);
        for(unsigned int m = 0; m < 60; ++m){
            bitsToMinutes[popcount(m)].push_back(string(m < 10, '0') + to_string(m));
        }

        vector<string> res;
        for(int hBits = 0; hBits <= turnedOn; ++hBits){
            int mBits = turnedOn - hBits;
            if(hBits >= (int)bitsToHours.size() || mBits >= (int)bitsToMinutes.size()){
                continue;
            }
            for(string& hStr: bitsToHours[hBits]){
                for(string& mStr: bitsToMinutes[mBits]){
                    res.push_back(hStr + ":" + mStr);
                }
            }
        }

        return res;
    }
};