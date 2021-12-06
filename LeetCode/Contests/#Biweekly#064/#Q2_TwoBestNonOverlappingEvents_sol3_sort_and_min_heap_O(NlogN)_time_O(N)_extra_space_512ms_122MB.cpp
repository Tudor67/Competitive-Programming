class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int N = events.size();
        
        sort(events.begin(), events.end());
        
        int answer = 0;
        int prevMaxVal = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(const vector<int>& EVENT: events){
            int startTime = EVENT[0];
            int endTime = EVENT[1];
            int val = EVENT[2];
            
            while(!minHeap.empty() && minHeap.top().first < startTime){
                prevMaxVal = max(prevMaxVal, minHeap.top().second);
                minHeap.pop();
            }
            
            answer = max(answer, prevMaxVal + val);
            minHeap.push({endTime, val});
        }
        
        return answer;
    }
};