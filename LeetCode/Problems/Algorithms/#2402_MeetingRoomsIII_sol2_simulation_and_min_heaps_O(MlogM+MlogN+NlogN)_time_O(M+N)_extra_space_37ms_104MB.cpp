class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using PLL = pair<long long, long long>;
        priority_queue<PLL, vector<PLL>, greater<PLL>> busyRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for(int room = 0; room < n; ++room){
            freeRooms.push(room);
        }

        vector<PLL> sortedMeetings;
        sortedMeetings.reserve(meetings.size());
        for(vector<int>& meeting: meetings){
            long long startTime = meeting[0];
            long long endTime = meeting[1];
            long long duration = endTime - startTime;
            sortedMeetings.push_back({startTime, duration});
        }

        sort(sortedMeetings.begin(), sortedMeetings.end());

        vector<int> freq(n);
        long long currTime = 0;
        for(PLL& meeting: sortedMeetings){
            long long startTime = meeting.first;
            long long duration = meeting.second;

            currTime = max(currTime, startTime);

            if(freeRooms.empty()){
                currTime = max(currTime, busyRooms.top().first);
            }

            while(!busyRooms.empty() && busyRooms.top().first <= currTime){
                int room = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(room);
            }

            int room = freeRooms.top();
            freeRooms.pop();

            busyRooms.push({currTime + duration, room});
            freq[room] += 1;
        }

        return max_element(freq.begin(), freq.end()) - freq.begin();
    }
};