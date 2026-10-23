class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xClosest = max(x1, min(xCenter, x2));
        int yClosest = max(y1, min(yCenter, y2));
        int dx = xClosest - xCenter;
        int dy = yClosest - yCenter;
        return (dx * dx + dy * dy <= radius * radius);
    }
};