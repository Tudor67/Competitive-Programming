class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;

        double hourAngle = 30.0 * hour + 0.5 * minutes;
        double minuteAngle = 6.0 * minutes;
        double angle = abs(hourAngle - minuteAngle);

        return min(angle, 360.0 - angle);
    }
};