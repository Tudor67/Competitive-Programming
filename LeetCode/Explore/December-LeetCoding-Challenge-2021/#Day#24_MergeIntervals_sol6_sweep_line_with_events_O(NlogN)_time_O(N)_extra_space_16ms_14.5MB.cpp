class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        enum EventType { START, END };
        using Event = pair<int, EventType>;
        vector<Event> events(2 * N);
        for(int i = 0; i < N; ++i){
            int start = intervals[i][0];
            int end = intervals[i][1];
            events[i] = {start, EventType::START};
            events[i + N] = {end, EventType::END};
        }
        
        sort(events.begin(), events.end());
        
        vector<vector<int>> mergedIntervals;
        int activeIntervals = 0;
        int startPos = -1;
        for(const Event& EVENT: events){
            int pos = EVENT.first;
            int eventType = EVENT.second;
            if(eventType == EventType::START){
                activeIntervals += 1;
                if(activeIntervals == 1){
                    startPos = pos;
                }
            }else{
                activeIntervals -= 1;
                if(activeIntervals == 0){
                    mergedIntervals.push_back({startPos, pos});
                }
            }
        }
        
        return mergedIntervals;
    }
};