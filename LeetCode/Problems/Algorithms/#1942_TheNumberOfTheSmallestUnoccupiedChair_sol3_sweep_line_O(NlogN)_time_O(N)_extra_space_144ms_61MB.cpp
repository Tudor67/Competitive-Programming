class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int N = times.size();

        enum EventType { ARRIVAL = 1, LEAVING = -1 };
        using Event = tuple<int, EventType, int>;
        vector<Event> events(2 * N);
        for(int i = 0; i < N; ++i){
            events[i] = {times[i][0], EventType::ARRIVAL, i};
            events[i + N] = {times[i][1], EventType::LEAVING, i};
        }

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> freeChairsMinHeap;
        for(int i = 0; i < N; ++i){
            freeChairsMinHeap.push(i);
        }

        vector<int> chairOf(N, -1);
        for(const Event& EVENT: events){
            EventType eventType = get<1>(EVENT);
            int friendIndex = get<2>(EVENT);

            if(eventType == EventType::ARRIVAL){
                chairOf[friendIndex] = freeChairsMinHeap.top();
                freeChairsMinHeap.pop();
            }else{
                freeChairsMinHeap.push(chairOf[friendIndex]);
                chairOf[friendIndex] = -1;
            }

            if(friendIndex == targetFriend){
                return chairOf[targetFriend];
            }
        }

        return -1;
    }
};