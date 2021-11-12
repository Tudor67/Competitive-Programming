class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int N = times.size();
        
        enum EventType{ SIT = 1, LEAVE = 0 };
        using Event = tuple<int, EventType, int>;
        vector<Event> events(2 * N);
        for(int i = 0; i < N; ++i){
            int sitTime = times[i][0];
            int leaveTime = times[i][1];
            events[i] = {sitTime, EventType::SIT, i};
            events[i + N] = {leaveTime, EventType::LEAVE, i};
        }
        
        sort(events.begin(), events.end());
        
        vector<int> chairOf(N, -1);
        set<int> freeChairs;
        for(int i = 0; i < N; ++i){
            freeChairs.insert(i);
        }
        
        for(const Event& EVENT: events){
            int t, eventType, i;
            tie(t, eventType, i) = EVENT;
            
            if(eventType == EventType::SIT){
                chairOf[i] = *freeChairs.begin();
                freeChairs.erase(freeChairs.begin());
            }else{
                freeChairs.insert(chairOf[i]);
                chairOf[i] = -1;
            }
            
            if(i == targetFriend){
                return chairOf[targetFriend];
            }
        }
        
        return -1;
    }
};