class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> delta;
        for(vector<int>& meeting: meetings){
            int l = meeting[0];
            int r = meeting[1];
            delta[l] += 1;
            delta[r + 1] -= 1;
        }

        int activeDays = 0;
        int activeMeetings = 0;
        int prevDay = 1;
        for(auto& [currDay, currDelta]: delta){
            if(activeMeetings >= 1){
                activeDays += (currDay - prevDay);
            }
            activeMeetings += currDelta;
            prevDay = currDay;
        }

        return (days - activeDays);
    }
};