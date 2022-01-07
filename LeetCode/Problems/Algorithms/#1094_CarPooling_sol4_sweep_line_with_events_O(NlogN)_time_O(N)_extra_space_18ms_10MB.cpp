class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int N = trips.size();
        
        using Location = int;
        using Passengers = int;
        using Event = pair<Location, Passengers>;
        
        vector<Event> events(2 * N);
        for(int i = 0; i < N; ++i){
            int p = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];
            events[i] = {from, p};
            events[i + N] = {to, -p};
        }
        
        sort(events.begin(), events.end());
        
        int passengers = 0;
        for(const Event& EVENT: events){
            passengers += EVENT.second;
            if(passengers > capacity){
                return false;
            }
        }
        
        return true;
    }
};