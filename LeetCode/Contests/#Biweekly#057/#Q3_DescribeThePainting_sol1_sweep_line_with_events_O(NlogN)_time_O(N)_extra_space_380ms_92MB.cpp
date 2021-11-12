class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        const int N = segments.size();
        
        enum EventType{ SEGMENT_START = 1, SEGMENT_END = 0 };
        using Event = tuple<int, EventType, int>;
        vector<Event> events(2 * N);
        for(int i = 0; i < N; ++i){
            int startPos = segments[i][0];
            int endPos = segments[i][1];
            int color = segments[i][2];
            events[i] = {startPos, EventType::SEGMENT_START, color};
            events[i + N] = {endPos, EventType::SEGMENT_END, color};
        }
        
        sort(events.begin(), events.end());
        
        vector<vector<long long>> painting;
        int prevPos = get<0>(events[0]);
        long long currentColor = 0;
        for(const Event& EVENT: events){
            int pos, eventType, color;
            tie(pos, eventType, color) = EVENT;
            
            if(prevPos != pos && currentColor >= 1){
                painting.push_back({prevPos, pos, currentColor});
            }
            
            if(eventType == EventType::SEGMENT_START){
                currentColor += color;
            }else{
                currentColor -= color;
            }
            
            prevPos = pos;
        }
        
        return painting;
    }
};