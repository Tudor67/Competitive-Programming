class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xDist = abs(x - z);
        int yDist = abs(y - z);
        if(xDist < yDist){
            return 1;
        }else if(xDist > yDist){
            return 2;
        }
        return 0;
    }
};