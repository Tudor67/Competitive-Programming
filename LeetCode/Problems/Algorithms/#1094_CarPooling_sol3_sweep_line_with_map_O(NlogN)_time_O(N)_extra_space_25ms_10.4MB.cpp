class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int N = trips.size();
        
        map<int, int> passengersAt;
        for(int i = 0; i < N; ++i){
            int p = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            passengersAt[from] += p;
            passengersAt[to] -= p;
        }
        
        int passengers = 0;
        for(const pair<int, int>& P: passengersAt){
            passengers += P.second;
            if(passengers > capacity){
                return false;
            }
        }
        
        return true;
    }
};