class Solution {
private:
    const vector<int> MONTH_SIZE = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int computeDayOfYear(string& dateStr){
        int month = stoi(dateStr.substr(0, 2));
        int dayOfMonth = stoi(dateStr.substr(3));
        int dayOfYear = dayOfMonth + accumulate(MONTH_SIZE.begin(), MONTH_SIZE.begin() + month, 0);
        return dayOfYear;
    }
    
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string arriveDateStr = max(arriveAlice, arriveBob);
        string leaveDateStr = min(leaveAlice, leaveBob);
        int daysTogether = max(0, computeDayOfYear(leaveDateStr) - computeDayOfYear(arriveDateStr) + 1);
        return daysTogether;
    }
};