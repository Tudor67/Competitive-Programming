class Solution {
public:
    int mostBooked(int N, vector<vector<int>>& meetings) {
        const int M = meetings.size();

        using PLI = pair<long long, int>;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<PLI, vector<PLI>, greater<PLI>> busyRooms;
        for(int room = 0; room < N; ++room){
            freeRooms.push(room);
        }

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PLI>> waitingMeetings;
        for(vector<int>& meeting: meetings){
            int startTime = meeting[0];
            int endTime = meeting[1];
            int duration = endTime - startTime;
            waitingMeetings.push({startTime, duration});
        }

        vector<int> count(N);
        long long currTime = 0;
        while(!waitingMeetings.empty()){
            long long meetingStartTime = waitingMeetings.top().first;
            int meetingDuration = waitingMeetings.top().second;
            waitingMeetings.pop();

            currTime = max(currTime, meetingStartTime);
            if(freeRooms.empty()){
                currTime = max(currTime, busyRooms.top().first);
            }

            while(!busyRooms.empty() && busyRooms.top().first <= currTime){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            int room = freeRooms.top();
            freeRooms.pop();

            count[room] += 1;

            busyRooms.push({currTime + meetingDuration, room});
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};