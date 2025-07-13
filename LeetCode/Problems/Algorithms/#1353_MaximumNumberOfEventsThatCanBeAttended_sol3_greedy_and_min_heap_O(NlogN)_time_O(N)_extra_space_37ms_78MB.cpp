class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = events.size();

        vector<pair<int, int>> sortedEvents(N);
        for(int i = 0; i < N; ++i){
            sortedEvents[i] = {events[i][0], events[i][1]};
        }

        sort(sortedEvents.begin(), sortedEvents.end());

        int res = 0;
        int currDay = 1;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0;
        while(i < N || !minHeap.empty()){
            if(minHeap.empty()){
                currDay = sortedEvents[i].first;
            }

            while(i < N && sortedEvents[i].first == currDay){
                minHeap.push(sortedEvents[i].second);
                i += 1;
            }

            while(!minHeap.empty() && minHeap.top() < currDay){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                minHeap.pop();
                res += 1;
                currDay += 1;
            }
        }

        return res;
    }
};