class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Move the center of circle to (0, 0)
        x1 -= xCenter;
        x2 -= xCenter;
        y1 -= yCenter;
        y2 -= yCenter;

        xCenter = 0;
        yCenter = 0;

        // Check if any point (x, y) with (x1 <= x <= x2) and (y1 <= y <= y2)
        // satisfies (x * x + y * y <= radius * radius)
        int minSqrDX = 0;
        if(x1 * x2 > 0){
            minSqrDX = min(x1 * x1, x2 * x2);
        }

        int minSqrDY = 0;
        if(y1 * y2 > 0){
            minSqrDY = min(y1 * y1, y2 * y2);
        }

        return (minSqrDX + minSqrDY <= radius * radius);
    }
};