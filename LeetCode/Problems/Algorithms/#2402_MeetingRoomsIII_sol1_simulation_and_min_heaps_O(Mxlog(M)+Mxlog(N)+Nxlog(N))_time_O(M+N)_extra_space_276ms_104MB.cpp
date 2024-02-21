class Solution {
public:
    int mostBooked(int N, vector<vector<int>>& meetings) {
        const int M = meetings.size();

        vector<pair<int, int>> sortedMeetings(M);
        for(int i = 0; i < M; ++i){
            sortedMeetings[i] = {meetings[i][0], meetings[i][1]};
        }

        sort(sortedMeetings.begin(), sortedMeetings.end());

        using PLI = pair<long long, int>;
        priority_queue<PLI, vector<PLI>, greater<PLI>> busyHeap;
        priority_queue<int, vector<int>, greater<int>> freeHeap;
        for(int room = 0; room < N; ++room){
            freeHeap.push(room);
        }

        vector<int> meetingsCount(N);
        long long currentTime = 0;
        for(int i = 0; i < M; ++i){
            long long meetingStart = sortedMeetings[i].first;
            int meetingDuration = sortedMeetings[i].second - sortedMeetings[i].first;

            currentTime = max(currentTime, meetingStart);
            if(freeHeap.empty()){
                currentTime = max(currentTime, busyHeap.top().first + 1);
            }
            while(!busyHeap.empty() && busyHeap.top().first < currentTime){
                int room = busyHeap.top().second;
                freeHeap.push(room);
                busyHeap.pop();
            }
            
            int room = freeHeap.top();
            freeHeap.pop();
            busyHeap.push({currentTime + meetingDuration - 1, room});

            meetingsCount[room] += 1;
        }

        return max_element(meetingsCount.begin(), meetingsCount.end()) - meetingsCount.begin();
    }
};