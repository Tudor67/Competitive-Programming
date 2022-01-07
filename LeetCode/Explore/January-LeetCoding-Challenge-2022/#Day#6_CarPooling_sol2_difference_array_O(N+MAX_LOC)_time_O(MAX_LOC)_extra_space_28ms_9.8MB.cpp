class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxLoc = 0;
        for(const vector<int>& T: trips){
            int to = T[2];
            maxLoc = max(maxLoc, to);
        }
        
        vector<int> diff(maxLoc + 1);
        for(const vector<int>& T: trips){
            int p = T[0];
            int from = T[1];
            int to = T[2];
            diff[from] += p;
            diff[to] -= p;
        }
        
        int passengers = 0;
        for(int i = 0; i <= maxLoc; ++i){
            passengers += diff[i];
            if(passengers > capacity){
                return false;
            }
        }
        
        return true;
    }
};