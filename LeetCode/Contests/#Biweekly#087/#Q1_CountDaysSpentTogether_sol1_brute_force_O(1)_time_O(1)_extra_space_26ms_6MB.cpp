class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const vector<int> MONTH_SIZE = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int daysTogether = 0;
        for(int month = 1; month <= 12; ++month){
            for(int day = 1; day <= MONTH_SIZE[month]; ++day){
                string monthStr = (month <= 9 ? "0" + to_string(month) : to_string(month));
                string dayStr = (day <= 9 ? "0" + to_string(day) : to_string(day));
                string currentDate = monthStr + "-" + dayStr;
                if(arriveAlice <= currentDate && currentDate <= leaveAlice &&
                   arriveBob <= currentDate && currentDate <= leaveBob){
                    daysTogether += 1;
                }
            }
        }
        
        return daysTogether;
    }
};