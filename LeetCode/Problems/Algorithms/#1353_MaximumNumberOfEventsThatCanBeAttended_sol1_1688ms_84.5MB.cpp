class Solution {
private:
    static bool comp(const vector<int>& lhs, const vector<int>& rhs){
        return (lhs[0] < rhs[0]);
    }
    
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int min_day = events[0][0];
        int max_day = events[0][1];
        for(const vector<int>& event: events){
            min_day = min(event[0], min_day);
            max_day = max(event[1], max_day);
        }
        
        int answer = 0;
        int last_inserted_event = -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int day = min_day; day <= max_day; ++day){
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
            for(int i = last_inserted_event + 1; i < events.size() && events[i][0] <= day; ++i){
                pq.push(events[i][1]);
                last_inserted_event = i;
            }
            if(!pq.empty()){
                answer += 1;
                pq.pop();
            }
        }
        
        return answer;
    }
};