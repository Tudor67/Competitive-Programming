class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int N = intervals.size();
        const int Q = queries.size();
        
        // Step 1: prepare events
        enum EventType{ INTERVAL_START, QUERY, INTERVAL_END };
        using Event = tuple<int, EventType, int>;
        
        vector<Event> events;
        for(int i = 0; i < N; ++i){
            events.emplace_back(intervals[i][0], INTERVAL_START, i);
            events.emplace_back(intervals[i][1], INTERVAL_END, i);
        }
        
        for(int i = 0; i < Q; ++i){
            events.emplace_back(queries[i], QUERY, i);
        }
        
        sort(events.begin(), events.end());
        
        // Step 2: sweep line
        vector<int> answer(Q);
        multiset<int> activeSizes;
        for(const Event& EVENT: events){
            int x, eventType, idx;
            tie(x, eventType, idx) = EVENT;
            
            if(eventType == INTERVAL_START){
                activeSizes.insert(intervals[idx][1] - intervals[idx][0] + 1);
            }else if(eventType == QUERY){
                if(activeSizes.empty()){
                    answer[idx] = -1;
                }else{
                    answer[idx] = *activeSizes.begin();
                }
            }else if(eventType == INTERVAL_END){
                activeSizes.erase(activeSizes.find(intervals[idx][1] - intervals[idx][0] + 1));
            }
        }
        
        return answer;
    }
};