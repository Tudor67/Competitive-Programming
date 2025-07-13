class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = events.size();

        unordered_map<int, vector<int>> endDaysFor;
        int maxDay = 0;
        for(vector<int>& event: events){
            int startDay = event[0];
            int endDay = event[1];
            endDaysFor[startDay].push_back(endDay);
            maxDay = max(maxDay, endDay);
        }

        int res = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int currDay = 1; currDay <= maxDay; ++currDay){
            while(!minHeap.empty() && minHeap.top() < currDay){
                minHeap.pop();
            }
            if(endDaysFor.count(currDay)){
                for(int endDay: endDaysFor[currDay]){
                    minHeap.push(endDay);
                }
            }
            if(!minHeap.empty() && currDay <= minHeap.top()){
                minHeap.pop();
                res += 1;
            }
        }

        return res;
    }
};