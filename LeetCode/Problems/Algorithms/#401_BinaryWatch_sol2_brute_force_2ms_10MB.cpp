class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(unsigned int h = 0; h < 12; ++h){
            for(unsigned int m = 0; m < 60; ++m){
                if(popcount(h) + popcount(m) == turnedOn){
                    res.push_back(to_string(h) + ":" + string(m < 10, '0') + to_string(m));
                }
            }
        }
        return res;
    }
};