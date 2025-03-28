class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        const int N = meetings.size();

        vector<pair<int, int>> sortedMeetings(N);
        for(int i = 0; i < N; ++i){
            sortedMeetings[i] = {meetings[i][0], meetings[i][1]};
        }

        sort(sortedMeetings.begin(), sortedMeetings.end());

        int freeDays = 0;
        int lastDay = 0;
        for(auto& [l, r]: sortedMeetings){
            if(lastDay < l){
                freeDays += l - lastDay - 1;
            }
            lastDay = max(lastDay, r);
        }

        freeDays += (days - lastDay);

        return freeDays;
    }
};