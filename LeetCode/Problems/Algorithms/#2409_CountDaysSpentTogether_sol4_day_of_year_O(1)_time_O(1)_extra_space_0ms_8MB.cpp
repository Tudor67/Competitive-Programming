class Solution {
private:
    const vector<int> MONTH_DAYS = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDayOfYear(const string& DATE){
        int mm = (DATE[0] - '0') * 10 + (DATE[1] - '0');
        int dd = (DATE[3] - '0') * 10 + (DATE[4] - '0');
        int dayOfYear = dd;
        for(int month = 1; month <= mm - 1; ++month){
            dayOfYear += MONTH_DAYS[month];
        }
        return dayOfYear;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int firstDayTogether = max(dateToDayOfYear(arriveAlice), dateToDayOfYear(arriveBob));
        int lastDayTogether = min(dateToDayOfYear(leaveAlice), dateToDayOfYear(leaveBob));
        return max(0, lastDayTogether - firstDayTogether + 1);
    }
};