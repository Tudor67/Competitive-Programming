class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const vector<int> MONTH_SIZE = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        string arriveDate = max(arriveAlice, arriveBob);
        string leaveDate = min(leaveAlice, leaveBob);
        
        int month = stoi(arriveDate.substr(0, 2));
        int day = stoi(arriveDate.substr(3));
        int leaveMonth = stoi(leaveDate.substr(0, 2));
        int leaveDay = stoi(leaveDate.substr(3));
        
        int daysTogether = 0;
        while(pair<int, int>{month, day} <= pair<int, int>{leaveMonth, leaveDay}){
            daysTogether += 1;
            day += 1;
            if(day > MONTH_SIZE[month]){
                day = 1;
                month += 1;
            }
        }
        
        return daysTogether;
    }
};