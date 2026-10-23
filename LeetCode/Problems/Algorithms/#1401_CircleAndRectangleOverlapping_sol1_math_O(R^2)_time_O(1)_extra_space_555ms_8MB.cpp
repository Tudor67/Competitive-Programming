class Solution {
private:
    bool isInsideCircle(int x, int y, int xCenter, int yCenter, int radius){
        int dx = x - xCenter;
        int dy = y - yCenter;
        return (dx * dx + dy * dy <= radius * radius);
    }

    bool isInsideRectangle(int x, int y, int x1, int y1, int x2, int y2){
        return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
    }

public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int x = xCenter - radius; x <= xCenter + radius; ++x){
            for(int y = yCenter - radius; y <= yCenter + radius; ++y){
                if(isInsideCircle(x, y, xCenter, yCenter, radius) &&
                   isInsideRectangle(x, y, x1, y1, x2, y2)){
                    return true;
                }
            }
        }
        return false;
    }
};