class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        double start = 5.0 * hour + minutes / 12.0;
        double end = minutes;
        double dist = max(start, end) - min(start, end);
        double answer = 6.0 * dist;
        if(answer >= 180){
            answer = 360 - answer;
        }
        return answer;
    }
};